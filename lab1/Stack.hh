#pragma once

#include "List.hh"
#include<iostream>

using namespace std;

template <typename T>
class Stack {
  List<T> lstack;
public:
  /*lista zawarta w stosie wywola swoj kontruktor co ustawi 
    wskaznik head na nullptr*/
  Stack(){}
  
   /*zablokowanie mozliwosci wywolywania kontruktora kopiującego dla stosu*/
  Stack(const Stack<T>& stack2)=delete;
  
  /*poniewaz to lista zawarta w stosie alokuje pamiec to ona bedzie 
    zwalniac pamiec a nie sam stos*/
  ~Stack(){}
  
  /*zablokowanie możliwości operatora przypisania dla stosu*/
  Stack<T>& operator = (Stack<T> stack2)=delete;

  void push(const T& newElement);
  T pop();
  void Display();
  bool isEmpty();
};

template <typename T>
void Stack<T>::push(const T& newElement) {
  lstack.pushFront(newElement);
}

template <typename T>
T Stack<T>::pop() {
  return lstack.popFront();
}

template <typename T>
void Stack<T>::Display() {
  lstack.Display();
}

template <typename T>
bool Stack<T>::isEmpty() {
  return lstack.isEmpty();
}
  
