/*
 * =====================================================================================
 *
 *       Filename:  list.h
 *
 *    Description:  list data structure
 *
 *        Version:  1.0
 *        Created:  2014年03月26日 20时44分00秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  ollyblue (ollybluew@gmail.com)
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef _ALGO_LIST_H
#define _ALGO_LIST_H

struct Node
{
  int d;
  Node* next;
};

Node* CreateList()
{
  Node *p = new Node;
  p->d = 0; // not used
  p->next = NULL;
  return p;
}

void PListRecurse(Node *head)
{
  if( head == NULL )
  {
    return;
  }
  if( head->next != NULL )
  {
    printf("%d ", head->d);
    PListRecurse(head->next);
  }
  else
  {
    printf("%d ", head->d);
  }
}

void PList(Node *head)
{
  Node* p = head->next;
  while(p)
  {
    printf("%d \tp:%016lX \n", p->d, reinterpret_cast<uint64_t>(p));
    p = p->next;
  }
}

void MakeCircle(Node* head)
{
  Node* p = head->next;
  while(p->next)
  {
    p = p->next;
  }
  p->next = head;
}

Node* GetNode(Node* head, int pos)
{
  Node* p = head->next;
  while( pos-- && p )
  {
    p = p->next;
  }
  return p;
}


int CheckCircle(Node* head)
{
  Node* p = head->next;
  Node* q = head->next;
  if( q )
  {
    q = q->next;
  }
  int i = 0;
  while( p && p->next && q && q->next )
  {
    // printf("\n p:%016lX q:%016lX\n", reinterpret_cast<uint64_t>(p), reinterpret_cast<uint64_t>(q));
    if( p == q )
    {
      return i;
    }
    // printf("i:%d v:%d\n",i, p->d);
    p = p->next;
    q = q->next;
    if( q )
    {
      q = q->next;
    }
    // printf("\n aa p:%016lX q:%016lX\n", reinterpret_cast<uint64_t>(p), reinterpret_cast<uint64_t>(q));
    i++;
  }
  return 0;
}

// ret greater than 0 has intersection
int CheckUnion(Node* head1, Node* head2)
{
  if( head1 == head2 )
  {
    return 1;
  }
  int ret1 = CheckCircle(head1);
  int ret2 = CheckCircle(head2);
  Node* p = head1->next;
  Node* q = head2->next;

  printf("ret1:%d ret2:%d\n", ret1, ret2);
  if( ret1 > 0 )
  {
    if( 0 == ret2 ) // 如果一个有环，另一个没环，则两个链表不可能相交
    {
      return -1;
    }
    if( ret2 > 0 ) // 两个都有环,则在大环前进 2*ret 之前如果有两同的指针，即相交，否则两个环不相交
    {
      int ret = ret1 > ret2 ? ret1 : ret2;
      while(ret-- && q && p)
      {
        q = q->next;
        if( q )
        {
          q = q->next;
        }
        p = p->next;
        printf("\n p:%016lX q:%016lX\n", reinterpret_cast<uint64_t>(p), reinterpret_cast<uint64_t>(q));
        if( p == q )
        {
          return 1;
        }
      }
      return 0; // 不相交 
    }
  }

  // 两个链表都没有环，则循环遍历即可
  p = head1->next;
  while( p && q )
  {
    while( q )
    {
      printf("\n p:%016lX q:%016lX\n", reinterpret_cast<uint64_t>(p), reinterpret_cast<uint64_t>(q));
      if( p == q )
      {
        return 1;
      }
      q = q->next;
    }
    q = head2->next;
    p = p->next;
  }

  return 0;
}

int InsertList(Node* head, int iValue, size_t dwPos = 0)
{
  Node* pNew = new Node;
  pNew->d = iValue;
  if( 0 == dwPos )
  {
    pNew->next = head->next;
    head->next = pNew;
    return dwPos;
  }
  Node* q = head->next;
  int i = 0;
  while( dwPos-- > 0 && q )
  {
    if( 0 == dwPos || NULL == q->next )
    {
      pNew->next = q->next;
      q->next = pNew;
      break;
    }
    else
    {
      q = q->next;
    }
    i++;
  }
  if( NULL == q )
  {
    return -1;
  }
  return 0;
}
 
int FindInList(Node* head, int key)
{
  int pos = 0;
  Node* p = head->next;
  while(p)
  {
    if( p->d == key )
    {
      break;
    }
    p = p->next;
    pos++;
  }
  if( p == NULL )
  {
    pos = -1;
  }
  return pos;
}

#endif // !_ALGO_LIST_H
