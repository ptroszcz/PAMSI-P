#pragma once

#include <iostream>
#include "PNode.hh"

template <typename T>
class PriorityQueue {
  
  PNode<T>* phead;

public:
  PriorityQueue() {
    phead=nullptr;
  }

  /*zablokowanie mozliwosci wywolywania kontruktora kopiującego dla tej struktury*/
  PriorityQueue(const PriorityQueue<T>& pqueue)=delete;
  
  ~PriorityQueue() {
    if (phead!=nullptr){
      while (phead->getNext() != nullptr) {
	PNode<T>* temp = phead;
	phead=phead->getNext();
	delete temp;
      }
     delete phead;
    }
  }

  /*zablokowanie możliwości operatora przypisania dla kolejki priorytetowej*/
  PriorityQueue<T>& operator = (PriorityQueue<T> pqueue)=delete;

  void enqueue(const T& newElement, int newPriority);
  T dequeue();
  void Display();
  bool isEmpty();
};

template <typename T>
void PriorityQueue<T>::enqueue(const T& newElement, int newPriority) {
  PNode<T>* newPNode = new PNode<T>;
  newPNode->setValue(newElement);
  newPNode->setPriority(newPriority);
  if (phead==nullptr || phead->getPriority()<newPriority) {
    newPNode->setNext(phead);
    phead=newPNode; }
  else {
    PNode<T>* temp=phead;
    while ((temp->getNext()!=nullptr) && (((temp->getNext())->getPriority())>=newPriority))
      temp=temp->getNext();
    newPNode->setNext(temp->getNext());
    temp->setNext(newPNode);
  }
}

template <typename T>
T PriorityQueue<T>::dequeue() {
  PNode<T>* temp=phead;
  phead=temp->getNext();
  T denum=temp->getValue();
  delete temp;
  return denum;
}

template <typename T>
void PriorityQueue<T>::Display() {
  if (phead!=nullptr) {
    PNode<T>* temp=phead;
    cout<<"Zawartosci kolejki priorytetowej w formacie element|priorytet"<<endl;
    while (temp!=nullptr) {
      cout<<temp->getValue()<<"|"<<temp->getPriority()<<"   ";
      temp=temp->getNext(); }
  }
  else
    cout<<"Brak elementow w kolejce priorytetowej";
  cout<<endl;
}

template <typename T>
bool PriorityQueue<T>::isEmpty() {
  return (phead==nullptr);
}

	   
