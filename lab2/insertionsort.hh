#pragma once

#include <vector>
#include <iostream>

using namespace std;


template <typename T>
void insertion_sort(vector<T>& tab, int begin, int end) {
  for (int i=begin+1;i<=end;++i) {
    T temp=tab[i];
    int j=i-1;
    while (j>=begin && (tab[j]>temp)) {
      tab[j+1]=tab[j];
      j--; }
    tab[j+1]=temp;
  }
}
      
