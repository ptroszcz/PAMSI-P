#pragma once

#include <iostream>
#include "ListIterator.hh"
#include "ConstListIterator.hh"

using namespace std;

template <typename T>
class List {
  
  Node<T>* head;

public:
  List() {
    head=nullptr;
  }

  /*zablokowanie mozliwosci wywolywania kontruktora kopiującego dla listy*/
  List(const List<T>& list2)=delete; 
  ~List() {
    if (head!=nullptr){
      while (head->getNext() != nullptr) {
	Node<T>* temp = head;
	head=head->getNext();
	delete temp;
      }
     delete head;
    }
  }

  /*zablokowanie możliwości operatora przypisania dla listy*/
  List<T>& operator = (List<T> list2)=delete;
  ListIterator<T> begin();
  ListIterator<T> end();
  ConstListIterator<T> cbegin() const;
  ConstListIterator<T> cend() const;
  void pushFront(const T& newValue);
  void pushBack(const T& newValue);
  void insert(const T& newValue,unsigned int index);
  T popFront();
  T popBack();
  void remove(const T& value);
  T& operator[](unsigned int index);
  void Display();
  bool isEmpty();
};

template <typename T>
ListIterator<T> List<T>::begin() {
  return ListIterator<T>(head);
}

template <typename T>
ListIterator<T> List<T>::end() {
  return ListIterator<T>(nullptr);
}

template <typename T>
ConstListIterator<T> List<T>::cbegin() const {
  return ConstListIterator<T>(head);
}

template <typename T>
ConstListIterator<T> List<T>::cend() const {
  return ConstListIterator<T>(nullptr);
}

template <typename T>
void List<T>::pushFront(const T& newValue) {
  Node<T>* newNode = new Node<T>;
  newNode->setValue(newValue);
  newNode->setNext(head);
  head=newNode;
}
  
template <typename T>
void List<T>::pushBack(const T& newValue) {
  if (head!=nullptr) {
    Node<T>* temp=head;
    while (temp->getNext()!=nullptr)
      temp=temp->getNext();
    Node<T>* newNode = new Node<T>;
    newNode->setValue(newValue);
    temp->setNext(newNode);
  }
  else
    this->pushFront(newValue);
}

template <typename T>
void List<T>::insert(const T& newValue,unsigned int index){
  if (index==0)
    this->pushFront(newValue);
  else {
    Node<T>* temp=head;
    for (unsigned int i=0;i<index;++i) {
      if (temp==nullptr){
	cerr<<"Podany index przekracza liczbe elementow listy"<<endl;
	cerr<<"Element dodany na koniec listy"<<endl;
	this->pushBack(newValue);
	i=index;}
      else if ((i+1)==index){
      Node<T>* newNode = new Node<T>;
      newNode->setValue(newValue);
      newNode->setNext(temp->getNext());
      temp->setNext(newNode);
      }
      else temp=temp->getNext();
    }
  }
}

template <typename T>
T List<T>::popFront() {
  Node<T>* temp=head;
  head=temp->getNext();
  T popnum=temp->getValue();
  delete temp;
  return popnum;
}


template <typename T>
T List<T>::popBack() {
  if (head->getNext()==nullptr)
    return this->popFront();
  else {
    Node<T>* temp=head;
    Node<T>* temp2=head;
    temp=temp->getNext();
    while (temp->getNext()!=nullptr) {
      temp=temp->getNext();
      temp2=temp2->getNext();
    }
    temp2->setNext(nullptr);      
    T popnum=temp->getValue();
    delete temp;
    return popnum;
  }
}

template <typename T>
void List<T>::remove(const T& value) {
  if (head==nullptr)
    cout<<"Lista jest pusta"<<endl;
  else {
     Node<T>* temp=head;
     while ((temp!=nullptr)&&(temp->getValue()==value)) {
       temp=temp->getNext();
       this->popFront(); }
     if (temp!=nullptr) {
       Node<T>* temp2=head;
       temp=temp->getNext();
       while (temp!=nullptr) {
	 if (temp->getValue()==value){
	   temp2->setNext(temp->getNext());
	   temp->setNext(nullptr);
	   delete temp;
	   temp=temp2->getNext();
	 }
	 else {
	   temp=temp->getNext();
	   temp2=temp2->getNext();
	 }
       }
     }
  }
}

template <typename T>
T& List<T>::operator[](unsigned int index) {
   ListIterator<T> it=this->begin();
   for (unsigned int i=0;i<index;++i) {
     if (it!=nullptr)
       ++it;
     else {
       cerr<<"Wybrany index jest wiekszy niz liczba przechowywanych wartosci"<<endl;
       cerr<<"Zostanie zwrocona wartosc pierwszego elementu listy"<<endl;
       i=index;
       it=this->begin();
     }
   }
   if (it!=nullptr)
     return *it;
   else {  /*gdy podany index wskazuje nullptr*/
     cerr<<"Wybrany index jest wiekszy niz liczba przechowywanych wartosci"<<endl;
     cerr<<"Zostanie zwrocona wartosc pierwszego elementu listy"<<endl;
     it=this->begin();
     return *it;
   }
}

template <typename T>
void List<T>::Display() {
  if (head!=nullptr){
    ListIterator<T> it=this->begin();
    cout<<"Zawartość testowanej struktury"<<endl;
    while (it!=nullptr) {
      cout<<*it<<"   ";
      ++it;}
  }
  else
    cout<<"Brak elementow w testowanej strukturze";
  cout<<endl;
}

template <typename T>
bool List<T>::isEmpty() {
  return (head==nullptr);
}
