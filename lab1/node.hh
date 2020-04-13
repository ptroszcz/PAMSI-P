#pragma once

#include <iostream>

using namespace std;

template <typename T> 
class Node {

public:

  T value;
  Node* next;

  Node();    
  Node(const Node<T>& node); 
  ~Node(){} 

  Node<T>& operator = (const Node<T>& node);
  void setValue(T newValue);
  T& getValue();
  void setNext(Node* newNext);
  Node<T>* getNext() const;
};
  
template <typename T>
Node<T>::Node() {
  value=0;
  next=nullptr;
  }


template <typename T>
Node<T>& Node<T>::operator = (const Node<T>& node) {
  value=node.value;
  next=node.next;
  return *this;
}

template <typename T>
Node<T>::Node(const Node<T>& node) {
  this->value=node.value;
  this->next=node.next;
}

template <typename T>
void Node<T>::setValue(T newValue) {
  value=newValue; }

template <typename T>
T& Node<T>::getValue() {
  return value; }

template <typename T>
void Node<T>::setNext(Node* newNext) {
  next=newNext; }

template <typename T>
Node<T>* Node<T>::getNext() const {
  return next; }





  
  
