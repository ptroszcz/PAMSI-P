#include <iostream>
#include "List.hh"
#include "Stack.hh"
#include "Queue.hh"
#include "PriorityQueue.hh"
#include "Map.hh"
#include <algorithm>
#include <string>

List<int> ilist;
Stack<int> istack;
Queue<int> iqueue;
PriorityQueue<int> ipqueue;
Map<string,int> imap;


void ListaTest() {
  int choice=0;
  int number=0;
  int index=0;
  int count=0;
  cout<<"Menu:"<<endl;
  cout<<"1. Dodaj liczbe na poczatek listy"<<endl;
  cout<<"2. Dodaj liczbe na koniec listy"<<endl;
  cout<<"3. Wyswietl liczby z listy"<<endl;
  cout<<"4. Dodaj liczbe w wybrane miejsce"<<endl;
  cout<<"5. Usun liczbe z poczatku listy"<<endl;
  cout<<"6. Usun liczbe z konca listy"<<endl;
  cout<<"7. Usun wszystkie pola przechowujace wybrana liczbe"<<endl;
  cout<<"8. Wyswietl liczbe na podanym miejscu"<<endl;
  cout<<"9. Wyswietl menu"<<endl;
  cout<<"10. Zakoncz testy na liscie"<<endl;
  cout<<"11. Test iteratorow"<<endl;
  while(choice!=10){
    cout<<"Wybor:";
    cin>>choice;
    switch(choice){
    case 1:
      cout<<"Liczba na przod"<<endl;
      cin>>number;
      ilist.pushFront(number);
      break;
    case 2:
      cout<<"Liczba na tyl"<<endl;
      cin>>number;
      ilist.pushBack(number);
      break;
    case 3:
      ilist.Display();
      count=std::count_if(ilist.begin(),ilist.end(),[](int i){return i>0;});
      cout<<"Liczba elementow w tablicy większych od zera:"<<count<<endl;
      break;
    case 4:
      cout<<"Liczba"<<endl;
      cin>>number;
      cout<<"Index"<<endl;
      cin>>index;
      ilist.insert(number,index);
      break;
    case 5:
      if (ilist.isEmpty()) 
	cout<<"Lista jest pusta. Wybierz inna operacje."<<endl;
      else {
	number=ilist.popFront();
	cout<<"Usunieto z przodu liczbe:"<<number<<endl;}
      break;
    case 6:
      if (ilist.isEmpty()) 
	cout<<"Lista jest pusta. Wybierz inna operacje."<<endl;
      else {
	number=ilist.popBack();
	cout<<"Usunieto z tylu liczbe:"<<number<<endl;}
      break;
    case 7:
       if (ilist.isEmpty()) 
	cout<<"Lista jest pusta. Wybierz inna operacje."<<endl;
       else {
	 cout<<"Liczba do usuniecia"<<endl;
	 cin>>number;
	 ilist.remove(number);}
       break;
    case 8:
      if (ilist.isEmpty()) 
	cout<<"Lista jest pusta. Wybierz inna operacje."<<endl;
      else {
	cout<<"Index liczby do wyswietlenia"<<endl;
	cin>>index;
	cout<<"Liczba pod podanym indexem:";
	cout<<ilist[index]<<endl;}
      break;
    case 9:
      cout<<"Menu:"<<endl;
      cout<<"1. Dodaj liczbe na poczatek listy"<<endl;
      cout<<"2. Dodaj liczbe na koniec listy"<<endl;
      cout<<"3. Wyswietl liczby z listy"<<endl;
      cout<<"4. Dodaj liczbe w wybrane miejsce"<<endl;
      cout<<"5. Usun liczbe z poczatku listy"<<endl;
      cout<<"6. Usun liczbe z konca listy"<<endl;
      cout<<"7. Usun wszystkie pola przechowujace wybrana liczbe"<<endl;
      cout<<"8. Wyswietl liczbe na podanym miejscu"<<endl;
      cout<<"9. Wyswietl menu"<<endl;
      cout<<"10. Zakoncz testy na liscie"<<endl;
      cout<<"11. Test iteratorow"<<endl;
      break;
    case 10:
      cout<<"Zakonczono testy na liscie"<<endl;
      break;
    case 11:
      cout<<"Test metod listy cbegin() i begin():"<<endl;
      if (ilist.isEmpty()){
	cout<<"Lista jest pusta wiec brak otrzymania komunikatu innego niz ten"<<endl;
	cout<<"oznacza poprawnosc dzialania metod listy zwianych z iteratorami"<<endl;
	if (ilist.cbegin()!=nullptr)
	cout<<"Metoda cbegin() listy zwraca zly iterator"<<endl;
	if (ilist.begin()!=nullptr)
	  cout<<"Metoda begin() listy zwraca zly iteratpr"<<endl;
	if (ilist.cend()!=nullptr)
	  cout<<"Metoda cend() listy zwraca zly iterator"<<endl; 
	if (ilist.end()!=nullptr)
	  cout<<"Metoda end() listy zwraca zly iteratpr"<<endl;
      }
      else {
	cout<<"Wartosc na ktora wskazuje iterator const:"<<*(ilist.cbegin())<<endl;
	cout<<"Wartosc na ktora wskazuje iterator zwykly:"<<*(ilist.begin())<<endl;
	if (ilist.cend()!=nullptr)
	  cout<<"Metoda cend() listy zwraca zly iterator"<<endl;
	if (ilist.end()!=nullptr)
	  cout<<"Metoda end() listy zwraca zly iteratpr"<<endl;
	cout<<"Jezeli wskazywane wartosci sa takie same oraz nie pojawil sie"<<endl;
	cout<<"zaden komunikat o niepoprawnosci metod cend() i end()"<<endl;
	cout<<"to metody listy zwiazane z iteratorami sa poprawne"<<endl;
      }
      break;
    default:
      cout<<"Wybrano nieistniejaca opcje. Sprobuj ponownie."<<endl;
      break;
    }
  }
}


void StackTest() {
  int choice=0;
  int number=0;
  cout<<"Menu:"<<endl;
  cout<<"1. Dodaj element do stosu"<<endl;
  cout<<"2. Sciagnij element ze stosu"<<endl;
  cout<<"3. Wyswietl elementy na stosie"<<endl;
  cout<<"4. Wyswietl menu"<<endl;
  cout<<"5. Zakoncz testy na stosie"<<endl;
  while(choice!=5){
    cout<<"Wybor:";
    cin>>choice;
    switch(choice){
    case 1:
      cout<<"Dodawany element:"<<endl;
      cin>>number;
      istack.push(number);
      break;
    case 2:
       if (istack.isEmpty()) 
	cout<<"Stos jest pusty. Wybierz inna operacje."<<endl;
       else {
	 number=istack.pop();
	 cout<<"Zciagniety element:"<<number<<endl; }
      break;
    case 3:
      istack.Display();
      break;
    case 4:
      cout<<"Menu:"<<endl;
      cout<<"1. Dodaj element do stosu"<<endl;
      cout<<"2. Sciagnij element ze stosu"<<endl;
      cout<<"3. Wyswietl elementy na stosie"<<endl;
      cout<<"4. Wyswietl menu"<<endl;
      cout<<"5. Zakoncz testy na stosie"<<endl;
      break;
    case 5:
      cout<<"Zakonczono testy na stosie"<<endl;
      break;
    default:
      cout<<"Wybrano nieistniejaca opcje. Sprobuj ponownie."<<endl;
      break;
    }
  }
}

void QueueTest() {
  int choice=0;
  int number=0;
  cout<<"Menu:"<<endl;
  cout<<"1. Dodaj element do kolejki"<<endl;
  cout<<"2. Sciagnij element z kolejki"<<endl;
  cout<<"3. Wyswietl elementy w kolejce"<<endl;
  cout<<"4. Wyswietl menu"<<endl;
  cout<<"5. Zakoncz testy na kolejce"<<endl;
  while(choice!=5){
    cout<<"Wybor:";
    cin>>choice;
    switch(choice){
    case 1:
      cout<<"Dodawany element:"<<endl;
      cin>>number;
      iqueue.enqueue(number);
      break;
    case 2:
       if (iqueue.isEmpty()) 
	cout<<"Kolejka jest pusta. Wybierz inna operacje."<<endl;
       else {
	 number=iqueue.dequeue();
	 cout<<"Zciagniety element:"<<number<<endl; }
      break;
    case 3:
      iqueue.Display();
      break;
    case 4:
      cout<<"Menu:"<<endl;
      cout<<"1. Dodaj element do kolejki"<<endl;
      cout<<"2. Sciagnij element z kolejki"<<endl;
      cout<<"3. Wyswietl elementy w kolejce"<<endl;
      cout<<"4. Wyswietl menu"<<endl;
      cout<<"5. Zakoncz testy na kolejce"<<endl;
      break;
    case 5:
      cout<<"Zakonczono testy na kolejce"<<endl;
      break;
    default:
      cout<<"Wybrano nieistniejaca opcje. Sprobuj ponownie."<<endl;
      break;
    }
  }
}


void PriorityQueueTest() {
  int choice=0;
  int number=0;
  int prior=0;
  cout<<"Menu:"<<endl;
  cout<<"1. Dodaj element do kolejki priorytetowej"<<endl;
  cout<<"2. Sciagnij element z kolejki"<<endl;
  cout<<"3. Wyswietl elementy w kolejce wraz z ich priorytetami"<<endl;
  cout<<"4. Wyswietl menu"<<endl;
  cout<<"5. Zakoncz testy na kolejce priorytetowej"<<endl;
  while(choice!=5){
    cout<<"Wybor:";
    cin>>choice;
    switch(choice){
    case 1:
      cout<<"Dodawany element:"<<endl;
      cin>>number;
      cout<<"Priorytet dodawanego elementy:"<<endl;
      cin>>prior;
      ipqueue.enqueue(number,prior);
      break;
    case 2:
       if (ipqueue.isEmpty()) 
	cout<<"Kolejka jest pusta. Wybierz inna operacje."<<endl;
       else {
	 number=ipqueue.dequeue();
	 cout<<"Zciagniety element:"<<number<<endl; }
      break;
    case 3:
      ipqueue.Display();
      break;
    case 4:
      cout<<"Menu:"<<endl;
      cout<<"1. Dodaj element do kolejki"<<endl;
      cout<<"2. Sciagnij element z kolejki"<<endl;
      cout<<"3. Wyswietl elementy w kolejce wraz z ich priorytetami"<<endl;
      cout<<"4. Wyswietl menu"<<endl;
      cout<<"5. Zakoncz testy na kolejce priorytetowej"<<endl;
      break;
    case 5:
      cout<<"Zakonczono testy na kolejce priorytetowej"<<endl;
      break;
    default:
      cout<<"Wybrano nieistniejaca opcje. Sprobuj ponownie."<<endl;
      break;
    }
  }
}

void MapTest() {
  int choice=0;
  int number=0;
  string key="";
  cout<<"Menu:"<<endl;
  cout<<"1. Dodaj klucz wraz z jego wartoscia do tablicy"<<endl;
  cout<<"2. Zobacz wartosc wybranego klucza"<<endl;
  cout<<"3. Usun przechowywana wartosc odpowiadajaca podanemu kluczowi"<<endl;
  cout<<"4. Wyswietl wszystie wartosci przechowywane w tablicy"<<endl;
  cout<<"5. Wyswietl menu"<<endl;
  cout<<"6. Zakoncz testy na tablicy hashujacej"<<endl;
  while(choice!=6){
    cout<<"Wybor:";
    cin>>choice;
    switch(choice){
    case 1:
      cout<<"Podaj klucz:"<<endl;
      cin>>key;
      cout<<"Podaj jego wartosc:"<<endl;
      cin>>number;
      imap.insert(key,number);
      break;
    case 2:
      cout<<"Podaj klucz:"<<endl;
      cin>>key;
      number=imap[key];
      if (number==0)
	cout<<"Podany klucz nie zostal wczesniej wprowadzony do tablicy"<<endl;
      else
	cout<<"Wartosc wprowadzonego klucza: "<<number<<endl;
      break;
    case 3:
      cout<<"Podaj klucz ktorego wartosc chcesz usunac z tablicy"<<endl;
      cin>>key;
      imap.remove(key);
      break;
    case 4:
      cout<<"Zawartosc tablicy";
      imap.Display();
      break;
    case 5:
      cout<<"Menu:"<<endl;
      cout<<"1. Dodaj klucz wraz z jego wartoscia do tablicy"<<endl;
      cout<<"2. Zobacz wartosc wybranego klucza"<<endl;
      cout<<"3. Usun przechowywana wartosc odpowiadajaca podanemu kluczowi"<<endl;
      cout<<"4. Wyswietl wszystie wartosci przechowywane w tablicy"<<endl;
      cout<<"5. Wyswietl menu"<<endl;
      cout<<"6. Zakoncz testy na tablicy hashujacej"<<endl;
      break;
    case 6:
      cout<<"Zakonczono testy na tabeli z hashowaniem"<<endl;
      break;
    default:
      cout<<"Wybrano nieistniejaca opcje. Sprobuj ponownie."<<endl;
      break;
    }
  }
}


int main() {
  int mchoice=0;
  while (mchoice!=6) {
    cout<<"Wybierz strukture do testowania"<<endl;
    cout<<"1. Lista"<<endl;
    cout<<"2. Stos"<<endl;
    cout<<"3. Kolejka"<<endl;
    cout<<"4. Kolejka priorytetowa"<<endl;
    cout<<"5. Tablica z hashowaniem"<<endl;
    cout<<"6. Zakoncz dzialanie programu"<<endl;
    cin>>mchoice;
    switch (mchoice) {
    case 1:
      ListaTest();
      break;
    case 2:
      StackTest();
      break;
    case 3:
      QueueTest();
      break;
    case 4:
      PriorityQueueTest();
      break;
    case 5:
      MapTest();
      break;
    case 6:
      cout<<"Zakonczono dzialanie programu"<<endl;
      break;
    default:
      cout<<"Wybrano nieistniejaca opcje. Sprobuj ponownie"<<endl;
      break;
    }
  }     
   return 0;
}
