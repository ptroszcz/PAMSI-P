#pragma once 

#include <iostream>

using namespace std;

template <typename T>
class PNode {

public:
  T value;
  PNode* next;
  int priority;

  PNode() {
    value=0;
    next=nullptr;
    priority=0;
  }

  PNode(const PNode<T>& pnode) {
    this->value=pnode.value;
    this->next=pnode.next;
    this->priority=pnode.priority;
  }
  ~PNode(){}

  PNode<T>& operator = (const PNode<T>& pnode) {
    this->value=pnode.value;
    this->next=pnode.next;
    this->priority=pnode.priority;
    return *this;
  }

  void setValue(T newValue);
  T& getValue();
  void setNext(PNode* newNext);
  PNode<T>* getNext() const;
  void setPriority(int prior);
  int& getPriority();
};

template <typename T>
void PNode<T>::setValue(T newValue) {
  value=newValue; }

template <typename T>
T& PNode<T>::getValue() {
  return value; }

template <typename T>
void PNode<T>::setNext(PNode* newNext) {
  next=newNext; }

template <typename T>
PNode<T>* PNode<T>::getNext() const {
  return next; }

template <typename T>
void PNode<T>::setPriority(int prior) {
  priority=prior; }

template <typename T>
int& PNode<T>::getPriority() {
  return priority; }
  
