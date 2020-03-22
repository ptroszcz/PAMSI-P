#pragma once

#include "List.hh"
#include<iostream>

using namespace std;

template <typename T>
class Queue {
  List<T> que;
public:
  /*lista zawarta w kolejce wywola swoj kontruktor co ustawi 
    wskaznik head na nullptr*/
  Queue(){}
  
   /*zablokowanie mozliwosci wywolywania kontruktora kopiującego dla kolejki*/
  Queue(const Queue<T>& que2)=delete;
  
  /*poniewaz to lista zawarta w stosie alokuje pamiec to ona bedzie 
    zwalniac pamiec a nie sama kolejka*/
  ~Queue(){}
  
  /*zablokowanie możliwości operatora przypisania dla kolejki*/
  Queue<T>& operator = (Queue<T> que2)=delete;

  void enqueue(const T& newElement);
  T dequeue();
  void Display();
  bool isEmpty();
};

template <typename T>
void Queue<T>::enqueue(const T& newElement) {
  que.pushBack(newElement);
}

template <typename T>
T Queue<T>::dequeue() {
  return que.popFront();
}

template <typename T>
void Queue<T>::Display() {
  que.Display();
}

template <typename T>
bool Queue<T>::isEmpty() {
  return que.isEmpty();
}
  
