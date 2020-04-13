#pragma once

#include <iostream>
#include <vector>


using namespace std;


template <typename T>
void merge(vector<T>& tab, int begin, int end) {
  vector<T> temp(end-begin+1);
  int middle=(begin+end)/2;
  int b=begin;
  int m=middle+1;
  for(int i=begin;i<=end;++i)
    temp[i-begin]=tab[i];
  for(int i=begin;i<=end;++i) {
    if (b>middle) { 
      tab[i]=temp[m-begin];
      m++; }
    else {
      if (m>end) {
	tab[i]=temp[b-begin];
	b++; }
      else {
	if (temp[b-begin]<temp[m-begin]) {
	  tab[i]=temp[b-begin];
	  b++; }
	else {
	  tab[i]=temp[m-begin];
	  m++; }
      }
    }
  }
}

template <typename T>
void merge_sort(vector<T>& tab, int begin, int end){
  if (begin<end) {
    int middle=(begin+end)/2;
    merge_sort(tab,begin,middle);
    merge_sort(tab,middle+1,end);
    merge(tab,begin,end);
  }
}


  
  
