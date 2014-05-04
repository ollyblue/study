/*
 * =====================================================================================
 *
 *       Filename:  sort.cpp
 *
 *    Description:  for test sort algorithm
 *
 *        Version:  1.0
 *        Created:  2014年03月30日 10时49分49秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  ollyblue (ollybluew@gmail.com)
 *        Company:  
 *
 * =====================================================================================
 */

#include "include/sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <string.h>

void PArr(int arr[], size_t len)
{
  printf("\n");
  for(size_t i = 0; i < len; ++i)
  {
    printf("%d\n", arr[i]);
  }
  printf("\n");
}

void TestSelectSort(int arr[], size_t len)
{
  // PArr(arr, len);
  SelectSort(arr, len);
  // PArr(arr,len);
}

void TestInsertSort(int arr[], size_t len)
{
  // PArr(arr, len);
  InsertSort(arr, len);
  // PArr(arr,len);
}

int GenerateArr(int* &arr, size_t len)
{
  arr = new int[len];
  const uint32_t RAND_DEF = static_cast<uint32_t>(-1);
  srand(time(NULL));
  for(size_t i = 0; i < len; ++i)
  {
    arr[i] = rand() % RAND_DEF;
  }
  return 0;
}

void TestQuickSort(int arr[], size_t lo, size_t hi)
{
  //PArr(arr, hi - lo + 1);
  QuickSort(arr, lo, hi);
  //PArr(arr, hi - lo + 1);
}

void TestMergeSort(int arr[], size_t lo, size_t hi)
{
  int *tempArr = new int[hi - lo];
 // PArr(arr, hi - lo);
  MergeSort(arr, tempArr, lo, hi);
//  printf("\nafter merge sort:\n");
  //PArr(arr, hi - lo);
  delete []tempArr;
}

void TestShellSort(int arr[], int dwLargeArrLen)
{
//   PArr(arr, dwLargeArrLen);
  ShellSort(arr, dwLargeArrLen);
  // PArr(arr, dwLargeArrLen);
}

void Test4Def()
{
#define _TT 3 
#define _CC 0
#define _MM 1
#if _TT > 2 
  printf("TT > 2\n");
#endif

#if _TT > 2 || ( _MM && !_CC )
  printf("TT > 2 || ( _MM && !_CC )\n");
#endif
}

int main(int argc, const char *argv[])
{
// int arr[] = { 4, 9, 1, 3, 100, 20, 60 ,11};
  int *pLargeArr;
  size_t dwLargeArrLen = 100000000;
  GenerateArr(pLargeArr, dwLargeArrLen);

  clock_t begin = clock();

  Test4Def();

  if( argc > 1)
  {
    const char *pSort = argv[1];
    if( strncmp(pSort,"-select",sizeof("-select")) == 0 )
    {
      TestSelectSort(pLargeArr,dwLargeArrLen);
    }
    if( strncmp(pSort,"-insert",sizeof("-insert")) == 0 )
    {
      TestInsertSort(pLargeArr, dwLargeArrLen);
    }
    if( strncmp(pSort,"-quick",sizeof("-quick")) == 0 )
    {
      TestQuickSort(pLargeArr, 0, dwLargeArrLen - 1);
    }
    if( strncmp(pSort,"-merge",sizeof("-merge")) == 0 )
    {
      TestMergeSort(pLargeArr, 0, dwLargeArrLen);
    }
    if( strncmp(pSort,"-shell",sizeof("-shell")) == 0 )
    {
      TestShellSort(pLargeArr, dwLargeArrLen);
    }
  }

  clock_t end = clock();
  clock_t cost = end - begin;
  printf("cost time:%lf\n", (double)cost / CLOCKS_PER_SEC);
  
  return 0;
}
