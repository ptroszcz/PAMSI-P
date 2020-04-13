#pragma once

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void quick_sort(vector<T>& tab,int begin,int end) {
  if (begin<end) {
    T pivot=tab[(begin+end)/2];
    int b=begin;
    int e=end;
    while (b<=e){
      while((tab[b]<pivot) && (b<=end))
	b++;
      while((tab[e]>pivot) && (e>=begin))
	e--;
      if (b<=e) {
	T temp=tab[b];
	tab[b]=tab[e];
	tab[e]=temp;
	b++;
	e--;
      }
    }
    if (e>begin)
      quick_sort(tab,begin,e);
    if (b<end)
      quick_sort(tab,b,end);
  }
}


template <typename T>
void descending_quick_sort(vector<T>& tab,int begin,int end) {
  if (begin<end) {
    T pivot=tab[(begin+end)/2];
    int b=begin;
    int e=end;
    while (b<=e){
      while((tab[b]>pivot) && (b<=end))
	b++;
      while((tab[e]<pivot) && (e>=begin))
	e--;
      if (b<=e) {
	T temp=tab[b];
	tab[b]=tab[e];
	tab[e]=temp;
	b++;
	e--;
      }
    }
    if (e>begin)
      descending_quick_sort(tab,begin,e);
    if (b<end)
      descending_quick_sort(tab,b,end);
  }
}
