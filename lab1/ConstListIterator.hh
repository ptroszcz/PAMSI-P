#pragma once

#include <iostream>
#include "node.hh" 

using namespace std;

template <typename T>
class ConstListIterator {

  Node<T>* iter;

public:
  using difference_type = std::size_t;
  using value_type = T;
  using reference = T&;
  using pointer = T*;
  using iterator_category = std::input_iterator_tag;

  ConstListIterator(Node<T> *newNode):iter(newNode){}
  ConstListIterator():iter(nullptr){};
  
  ConstListIterator(const ConstListIterator<T>& it);
  Node<T>* test() {return iter;}
  
  ~ConstListIterator(){ }
  
  ConstListIterator<T>& operator =(const ConstListIterator<T>& it);
  ConstListIterator<T>& operator++();
  const T& operator*();
  bool operator!=(const ConstListIterator<T>& it);
};

template <typename T>
ConstListIterator<T>::ConstListIterator(const ConstListIterator<T>& it) {
  iter=it.iter;
}

template <typename T>
ConstListIterator<T>& ConstListIterator<T>::operator =(const ConstListIterator<T>& it) {
  iter=it.iter;
  return *this;
}

template <typename T>
ConstListIterator<T>& ConstListIterator<T>::operator++() {
  if (iter == nullptr) {
    cerr<<"Nie mozliwa inkrementacja. Iterator wskazuje na nullptr."<<endl;
    return *this; }
  iter=iter->getNext();
  return *this;
}


template <typename T>
const T& ConstListIterator<T>::operator*() {
  return iter->getValue();
}

template <typename T>
bool ConstListIterator<T>::operator!=(const ConstListIterator<T>& it){
  return this->iter!=it.iter;
}
