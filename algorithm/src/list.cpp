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

  i = FindInList(head, 20);
  printf("\nfind i:%d\n", i);
  
  return 0;
}
