/*
 * =====================================================================================
 *
 *       Filename:  list.cpp
 *
 *    Description:  for test list
 *
 *        Version:  1.0
 *        Created:  2014年03月26日 20时57分36秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  ollyblue (ollybluew@gmail.com)
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdint.h>
#include "include/list.h"

int main(int argc, const char *argv[])
{
  Node* head = CreateList();
  int v = 5;
  InsertList(head, v);
  InsertList(head, v);
  InsertList(head, v);
  v = 10;
  int i = InsertList(head, v, 4);
  v = 20;
  i = InsertList(head, v, 4);
  v = 1;
  i = InsertList(head, v);
  printf("i:%d\n", i);
  PList(head);
  printf("\n\n");
  PListRecurse(head->next);

  Node* p = GetNode(head, 1);
  if( NULL != p )
  {
    printf("\n0 node d:%d p:%016lX\n", p->d, reinterpret_cast<uint64_t>(p));
  }

  Node* head2 = CreateList();
  head2->next = p;
  printf("\nlist2\n");
  PList(head2);
  printf("\n");

  int retInterSection = CheckUnion(head, head2);
  printf("checkunion ret:%d\n", retInterSection);

  int ret = CheckCircle(head);
  printf("check circle:%d\n", ret);

  printf("makecircle \n");
  MakeCircle(head);
  //PList(head);

  retInterSection = CheckUnion(head, head2);
  printf("checkunion2 ret:%d\n", retInterSection);

  ret = CheckCircle(head);
  printf("check circle:%d\n", ret);

  i = FindInList(head, 20);
  printf("\nfind i:%d\n", i);
  
  return 0;
}
