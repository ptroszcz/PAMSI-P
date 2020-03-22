#pragma once

#include <iostream>
#include <string>

using namespace std;

template<typename KeyType, typename ValueType>
class Map {
  static const int size=100;
  ValueType tab[size];

public:
  
  Map(){
    for (int i=0;i<size;++i)
      tab[i]=0;
  }
  Map(const Map<KeyType,ValueType>& map2){
    for (int i=0;i<size;++i)
      tab[i]=map2.tab[i];
  }
  ~Map(){}

  Map<KeyType,ValueType>& operator = (Map<KeyType,ValueType> map2){
  for (int i=0;i<size;++i)
      tab[i]=map2.tab[i];
  }

  int fhash(const KeyType& key);
  void insert(const KeyType& key, const ValueType& value);
  ValueType& operator[](const KeyType& key);
  void remove(const KeyType& key);
  void Display();
};

template<typename KeyType, typename ValueType>
int Map<KeyType,ValueType>::fhash(const KeyType& key) {
  int value=0;
  for (unsigned int i=0;i<key.length();++i)
    value+=(int)key[i];
  return value%size;
}

template<typename KeyType, typename ValueType>
void Map<KeyType,ValueType>::insert(const KeyType& key, const ValueType& value){
  if (value==0) {
    cerr<<"Wartosc 0 przeznaczona jest jako wartosc oznaczajaca puste miejsce"<<endl;
    cerr<<"Wprowadz ponownie klucz podajac wartosc rozna od 0"<<endl;}
  else {
    if (tab[this->fhash(key)]!=0)
      cout<<"Nadpisano wartosc wczesniej wprowadzonego klucza"<<endl;
    tab[this->fhash(key)]=value;}
}

template<typename KeyType, typename ValueType>
ValueType& Map<KeyType,ValueType>::operator[](const KeyType& key){
  return tab[this->fhash(key)];
}

template<typename KeyType, typename ValueType>
void Map<KeyType,ValueType>::remove(const KeyType& key) {
  if (tab[this->fhash(key)]==0)
    cout<<"Podany klucz nie posiada zadnej przechowywanej wartosci w tabeli"<<endl;
  else
    tab[this->fhash(key)]=0;
}

template<typename KeyType, typename ValueType>
void Map<KeyType,ValueType>::Display() {
  for (int i=0;i<size;++i) {
    if (i%10==0)
      cout<<endl;
    cout<<tab[i]<<"  ";
  }
  cout<<endl;
}
