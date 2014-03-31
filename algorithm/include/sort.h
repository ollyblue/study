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
  size_t k = 0;
  size_t i = lo;
  size_t j = middle;

  while( i < middle && j < hi )
  {
    if( arr[i] > arr[j] )
    {
      tempArr[k++] = arr[j++];
    }
    else
    {
      tempArr[k++] = arr[i++];
    }
  }

  while( i < middle )
  {
    tempArr[k++] = arr[i++];
  }
  while( j < hi )
  {
    tempArr[k++] = arr[j++];
  }

  for(size_t m = 0; m < k; ++m)
  {
    arr[ lo + m ] = tempArr[m];
  }

  return 0;
}

int MergeSort(int arr[], int tmpArr[], size_t lo, size_t hi)
{
  if(lo + 1 < hi)
  {
    size_t middle = ( lo + hi ) / 2;
    MergeSort(arr, tmpArr, lo, middle);
    MergeSort(arr, tmpArr, middle, hi);
    Merge(arr, tmpArr, lo, hi, middle);
  }
  return 0;
}

void ShellSort(int arr[], int dwLargeArrLen)
{
  int temp;
  int n = dwLargeArrLen / 2 ;
  int index = 0;
  while( n  >= 1 )
  {
    for(index = n; index < (int)dwLargeArrLen; ++index)
    {
      temp = arr[index];
      int j = index - n;
      while( j >= 0 && arr[j] > temp )
      {
        arr[j + n] = arr[index];
        j = j - n;
      }
      arr[j + n] = temp;
    }
    n /= 2;
  }
}

#endif // !_ALGO_SORT_H
