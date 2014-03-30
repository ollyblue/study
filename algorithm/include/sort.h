/*
 * =====================================================================================
 *
 *       Filename:  sort.h
 *
 *    Description:  sort algorithm
 *
 *        Version:  1.0
 *        Created:  2014年03月30日 10时46分25秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  ollyblue (ollybluew@gmail.com)
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef _ALGO_SORT_H
#define _ALGO_SORT_H

#include <stddef.h>
#include <stdio.h>

int SelectSort(int arr[], size_t len)
{
  int nTemp = 0;
  for(size_t i = 0; i < len; ++i)
  {
    size_t min = i;
    for(size_t j = i + 1; j < len; ++j)
    {
      if( arr[min] > arr[j] )
      {
        min = j;
      }
    }
    nTemp = arr[i];
    arr[i] = arr[min];
    arr[min] = nTemp;
  }
  return 0;
}

int InsertSort(int arr[], size_t len)
{
  for(size_t i = 1; i < len; ++i)
  {
    for(size_t j = i; j > 0; --j)
    {
      if( arr[j] < arr[j-1] )
      {
        int nTemp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = nTemp;
      }
    }
  }
  return 0;
}

int QuickSort(int arr[], size_t lo, size_t hi)
{
  if(lo < hi)
  {
    int nTemp = arr[lo];
    size_t i = lo;
    size_t j = hi;
    while(i < j )
    {
      // 这里如果不加j>1的话，会溢出，然后产生core
      while( j > i && j > 1  && arr[j] > nTemp ) 
      {
        j--;
      }

      if( i < j )
      {
        arr[i++] = arr[j];
      }
      while( i < j && arr[i] < nTemp ) 
      {
        i++;
      }
      if( i < j )
      {
        arr[j] = arr[i];
      }
    }
    arr[i] = nTemp;
    QuickSort(arr, lo, i - 1);
    QuickSort(arr, i + 1, hi); 
 }
  return 0;
}

int Merge(int arr[], int tempArr[], size_t lo, size_t hi, size_t middle)
{
  size_t index1 = lo;
  size_t index2 = middle + 1;
  size_t index = lo;
  for(size_t i = lo; i <= hi; ++i)
  {
    tempArr[i] = arr[i];
  }
  for(size_t i = lo; i <= hi; ++i)
  {
    printf("tempArr[%zu]:%d\n", i, tempArr[i]);
  }

  while( (index1 <= middle) && 
        (index2 <= hi) )
  {
    printf("i1:%zu i2:%zu m:%zu hi:%zu\n", index1, index2, middle, hi);
    printf("tempArr[index1]:%d tempArr[index2]:%d\n", tempArr[index1], tempArr[index2]);
    if( tempArr[index1] > tempArr[index2] )
    {
      printf("a i1:%zu i2:%zu m:%zu\n", index1, index2, middle);
      printf("a tempArr[index1]:%d tempArr[index2]:%d\n", tempArr[index1], tempArr[index2]);
      arr[index++] = tempArr[index2++];
    }
    else
    {
      printf("b i1:%zu i2:%zu m:%zu hi:%zu\n", index1, index2, middle, hi);
      printf("b tempArr[index1]:%d tempArr[index2]:%d\n", tempArr[index1], tempArr[index2]);
      arr[index++] = tempArr[index1++];
      printf("c i1:%zu i2:%zu m:%zu\n", index1, index2, middle);
      printf("c tempArr[index1]:%d tempArr[index2]:%d\n", tempArr[index1], tempArr[index2]);
    }
    printf("d i1:%zu i2:%zu m:%zu\n", index1, index2, middle);
    printf("d tempArr[index1]:%d tempArr[index2]:%d\n", tempArr[index1], tempArr[index2]);
  }

  while(index1 <= middle)
  {
    arr[index++] = tempArr[index1++];
  }
  while(index2 <= hi )
  {
    arr[index++] = tempArr[index2++];
  }
  return 0;
}

int MergeSort(int arr[], int tmpArr[], size_t lo, size_t hi)
{
  while(lo < hi)
  {
    size_t middle = ( lo + hi ) / 2;
    if( middle < 1 ) return 0;
    MergeSort(arr, tmpArr, lo, middle);
    MergeSort(arr, tmpArr, middle + 1, hi);
    Merge(arr, tmpArr, lo, hi, middle + 1);
  }
  return 0;
}

#endif // !_ALGO_SORT_H
