#pragma once

#include <iostream>
#include "node.hh"

using namespace std;

template <typename T>
class ListIterator {

  Node<T>* iter;

public:
  using difference_type = std::size_t;
  using value_type = T;
  using reference = T&;
  using pointer = T*;
  using iterator_category = std::input_iterator_tag;

  ListIterator(Node<T> *newNode):iter(newNode){}
  ListIterator():iter(nullptr){};
  
  ListIterator(const ListIterator<T>& it);
  Node<T>* test() {return iter;}
  
  ~ListIterator(){ }
  
  ListIterator<T>& operator =(const ListIterator<T>& it);
  ListIterator<T>& operator++();
  T& operator*();
  bool operator!=(const ListIterator<T>& it);
};

template <typename T>
ListIterator<T>::ListIterator(const ListIterator<T>& it) {
  iter=it.iter;
}

template <typename T>
ListIterator<T>& ListIterator<T>::operator =(const ListIterator<T>& it) {
  iter=it.iter;
  return *this;
}

template <typename T>
ListIterator<T>& ListIterator<T>::operator++() {
  if (iter == nullptr) {
    cerr<<"Nie mozliwa inkrementacja. Iterator wskazuje na nullptr."<<endl;
    return *this; }
  iter=iter->getNext();
  return *this;
}


template <typename T>
T& ListIterator<T>::operator*() {
  return iter->getValue();
}

template <typename T>
bool ListIterator<T>::operator!=(const ListIterator<T>& it){
  return this->iter!=it.iter;
}
