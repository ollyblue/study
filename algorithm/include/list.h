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
    printf("%d ", p->d);
    p = p->next;
  }
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
