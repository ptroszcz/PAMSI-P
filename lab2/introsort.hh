#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include "heapsort.hh"
#include "insertionsort.hh"

using namespace std;

template <typename T>
void introsort(vector<T>& tab, int begin, int end, int depth) {
  if ((end-begin+1)>9) { 
    if (depth<=0)
      heap_sort(tab,begin,end);
    else {
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
	introsort(tab,begin,e,depth-1);
      if (b<end)
	introsort(tab,b,end,depth-1);
    }
  }
  else
    insertion_sort(tab,begin,end);
}
      




template <typename T>
void intro_sort(vector<T>& tab, int begin, int end){
  int deep=(int)floor(2*log(end-begin+1)/M_LN2);
  introsort(tab,begin,end,deep);
}
