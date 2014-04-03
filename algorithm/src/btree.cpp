/*
 * =====================================================================================
 *
 *       Filename:  btree.cpp
 *
 *    Description:  for test btree
 *
 *        Version:  1.0
 *        Created:  2014年04月03日 21时43分30秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  ollyblue (ollybluew@gmail.com)
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


struct BTree
{
  int data;
  BTree *left;
  BTree *right;
};

BTree* CreateTree();

BTree* Insert(BTree *root, int v);

void InBTree(BTree *root);

void LevelBTree(BTree *root);

int main(int argc, const char *argv[])
{
  BTree *pRoot = NULL;

  pRoot = CreateTree();

  InBTree(pRoot);
  printf("\n-----\n");
  LevelBTree(pRoot);

  return 0;
}

BTree *CreateTree()
{
  BTree *root = NULL;
  // printf("input node:\n");
  int arr[] = { 9, 200, 22, 45, 2, 99, 45, 32, 16, 85, 103 };
  int len = sizeof(arr) /  sizeof(arr[0]);
  //scanf("%d", &temp);
  printf("origin arr:\n");
  for(int i = 0; i < len; ++i)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
  int i = 0;
  while( ++i < len )
  {
    root = Insert(root, arr[i]);
  }

  return root;
}

BTree *Insert(BTree *root, int v)
{
  BTree *p = root;
  BTree *newNode = new BTree;
  newNode->data = v;
  newNode->left = NULL;
  newNode->right = NULL;

  BTree *tmpNode;

  if( !p )
  {
    return newNode; }
  else
  {
    while( p != NULL )
    {
      tmpNode = p;
      if( p->data >= v )
      {
        p = p->left;
      }
      else
      {
        p = p->right;
      }
    }

    if( tmpNode->data >= v )
    {
      tmpNode->left = newNode;
    }
    else
    {
      tmpNode->right = newNode;
    }
  }

  return root;
}

void InBTree(BTree *root)
{
  if( root == NULL )
  {
    return;
  }

  printf("addr:%016lX left:%016lX right:%016lX %d\n",
       reinterpret_cast<uint64_t>(root),
       reinterpret_cast<uint64_t>(root->left),
       reinterpret_cast<uint64_t>(root->right),
       root->data);
  InBTree(root->left);
  InBTree(root->right);
}

void LevelBTree(BTree *root)
{
  if( root == NULL )
  {
    return;
  }

  LevelBTree(root->left);
  printf("addr:%016lX left:%016lX right:%016lX %d\n",
       reinterpret_cast<uint64_t>(root),
       reinterpret_cast<uint64_t>(root->left),
       reinterpret_cast<uint64_t>(root->right),
       root->data);
  LevelBTree(root->right);
}
