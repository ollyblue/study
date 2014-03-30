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

#endif // !_ALGO_SORT_H
