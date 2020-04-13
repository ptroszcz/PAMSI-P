#include <iostream>
#include <fstream>
#include <vector>
#include "mergesort.hh"
#include "quicksort.hh"
#include "introsort.hh"
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>

using namespace std;




template <typename T>
bool isSortedWell(vector<T> tab) {
  for (unsigned int i=1;i<tab.size();++i) {
    if (tab[i]<tab[i-1])
      return false;
  }
  return true;
}

int main() {
  srand(time(NULL));
  chrono::high_resolution_clock timer;
  int size=10000;    /*wielkosc tablic*/
  int number_of_tabs=100; /*ilosc tablic*/
  int per=500;               /*wartosc okreslajaca ile promili tablicy ma byc posortowane*/
  int well_sorted=1;      /*zmienna pomocnicza w celu sprawdzenia poprawnosci sortowan*/
  ofstream sort_time("isort10kc.txt"); /*utworzenie strumienia ktory bedzie zapisywal czasy 
				                                     sortowan do pliku*/
  vector<vector<int>> tabs;
  for (int i=0;i<number_of_tabs;++i) {  /*generowanie 100 tablic o losowych wartosciach*/
    vector<int> tab;
    for (int j=0;j<size;++j) 
      tab.push_back(rand()%1000);
    tabs.push_back(tab);
  }
  for (unsigned int i=0;i<tabs.size();++i) 
    sort(tabs[i].begin(),tabs[i].begin()+(per*size)/1000); /*posortowanie wybranej czesci tablic*/
    //descending_quick_sort(tabs[i],0,tabs[i].size()-1);   /*posortowanie tablic malejaca*/
  for (unsigned int i=0;i<tabs.size();++i) {
    auto tstart=timer.now();
    //merge_sort(tabs[i],0,tabs[i].size()-1);
    //quick_sort(tabs[i],0,tabs[i].size()-1);
    intro_sort(tabs[i],0,tabs[i].size()-1);
    auto tend=timer.now();
    chrono::duration<double> sec=tend-tstart;
    sort_time<<sec.count()*1000<<endl; /*zapisanie do pliku czasow sortowan poszczegolnych tablic*/ 
  }
  sort_time.close();
  for (unsigned int i=0;i<tabs.size();++i) {
    if (!isSortedWell(tabs[i])) {
      cout<<"Źle posortowano tablice numer "<<i+1<<endl;
      well_sorted=0; }
  }
  if (well_sorted==1)
    cout<<"Dobrze posortowano wszystkie tablice"<<endl; 
  return 0;
}
