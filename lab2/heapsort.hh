#pragma once

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void heapmax(vector<T>& tab, int size, int ifather) {
  if (ifather<size) {
    int max=ifather;
    int ileft_son=2*ifather+1;
    int iright_son=2*ifather+2;
    if ((ileft_son<size) && (tab[ileft_son]>tab[max]))
      max=ileft_son;
    if ((iright_son<size) && (tab[iright_son]>tab[max]))
      max=iright_son;
    if (max != ifather) {
      T temp=tab[ifather];
      tab[ifather]=tab[max];
      tab[max]=temp;
      heapmax(tab,size,max);
    }
  }
}

template <typename T>
void heap_sort(vector<T>& tab,int begin, int end){
  int size = end-begin+1;
  vector<T> temp(size);
  for(int i=begin;i<=end;++i)
    temp[i-begin]=tab[i];
  for (int i=size/2-1; i>=0;--i) /*tworzenie kopca*/
    heapmax(temp,size,i);
  for (int i=size-1;i>0;--i) {
    T temp2=temp[0];
    temp[0]=temp[i];
    temp[i]=temp2;
    heapmax(temp,i,0);
  }
  for (int i=0;i<size;++i)
    tab[i+begin]=temp[i];
}
    
