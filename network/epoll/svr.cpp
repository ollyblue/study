

#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <strings.h>
#include <errno.h>

static int socket_create();
static int socket_bind(int fd, const char *ip, uint16_t port);
static int socket_listen(int fd, int acp_num);
static int poll_create(int size);
static int poll_add(int efd, int fd);


int main(int argc, const char *argv[])
{
  int fd;
  int acp_num = 10;

  fd = socket_create();
  if( fd <= 0 )
  {
    perror("create socket failed\n");
  }

  if( 0 != socket_bind(fd, "127.0.0.1", 8888) )
  {
    perror("bind error\n");
  }
  if( 0 != socket_listen(fd, acp_num) )
  {
    perror("listen error\n");
  }
   
  printf("socket suc\n");

  int efd;
  if( 0 != ( efd = poll_create(10) ) )
  {
    perror("epoll create failed\n");
  }
  if( 0 != poll_add(efd, fd) )
  {
    perror("epoll add failed\n");
  }

  epoll_event ents[20];
  int conn_fd;
  sockaddr_in client_addr;
  socklen_t client_len = sizeof(client_addr);
  epoll_event ev;
  int sock_fd;
  char buff[1024] = { 0 };
  int n;
  while(1)
  {
    int ret = epoll_wait(efd, ents, 20, 500);
    if( ret >= 0 )
    {
      for(int i = 0; i < ret; ++i)
      {
        if( ents[i].data.fd == fd )
        {
          conn_fd = accept(fd, reinterpret_cast<sockaddr*>(&client_addr), &client_len);
          if( conn_fd < 0 )
          {
            perror("accept error\n");
            return -1;
          }
          char *client_ip = inet_ntoa(client_addr.sin_addr);
          printf("accept a connection from:%s:%u\n", client_ip, ntohs(client_addr.sin_port));
        
          ev.data.fd = conn_fd;
          ev.events = EPOLLIN | EPOLLOUT;
          epoll_ctl(efd, EPOLL_CTL_ADD, conn_fd, &ev);
        }
        else if( ents[i].events & EPOLLIN )
        {
          if( ( sock_fd = ents[i].data.fd ) < 0 )
          {
            continue;
          }
          bzero(buff, sizeof(buff));
          if( ( n = read(sock_fd, buff, sizeof(buff))) < 0 )
          {
            if( errno == ECONNRESET )
            {
              close(sock_fd);
              ents[i].data.fd = -1;
            }
            else
            {
              perror("read error\n");
            }
          }
          else if( 0 == n )
          {
            close(sock_fd);
            ents[i].data.fd = -1;
          }
          buff[n] = '\0';

          printf("recv:%s\n", buff);

          ev.data.fd = sock_fd;
          ev.events = EPOLLIN | EPOLLOUT | EPOLLET;
          epoll_ctl(efd, EPOLL_CTL_MOD, sock_fd, &ev);
        }
        else if( ents[i].events & EPOLLOUT )
        {
          sock_fd = ents[i].data.fd;
          write(sock_fd, buff, n);

          ev.data.fd = sock_fd;
          ev.events = EPOLLIN | EPOLLOUT;
          epoll_ctl(efd, EPOLL_CTL_MOD, fd, &ev);
        }
      }
    }
    else
    {
      perror("error happen\n");
    }

  }
  
  return 0;
}

int socket_create()
{
  int fd = socket(AF_INET, SOCK_STREAM, 0);
  return fd;
}

int socket_bind(int fd, const char *ip, uint16_t port)
{
  sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = inet_addr(ip);
  addr.sin_port = htons(port);
  socklen_t len = sizeof(addr);
      
  int ret;
  ret = bind(fd, reinterpret_cast<sockaddr*>(&addr), len);
  return ret;
}

int socket_listen(int fd, int acp_num)
{
  return listen(fd, acp_num);
}

int poll_create(int size)
{
  return epoll_create(size);
}

int poll_add(int efd, int fd)
{
  epoll_event ent;
  ent.events = EPOLLIN | EPOLLOUT | EPOLLET;
  ent.data.fd = fd;

  return epoll_ctl(efd, EPOLL_CTL_ADD, fd, &ent);
}
