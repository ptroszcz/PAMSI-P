#include <iostream>
#include "List.hh"
#include "Stack.hh"
#include "Queue.hh"
#include "PriorityQueue.hh"
#include "Map.hh"
#include <algorithm>
#include <string>
#include <list>
#include <stack>
#include <queue>
#include <unordered_map>

List<int> ilist;
list<int> stl_list;
Stack<int> istack;
stack<int> stl_stack;
Queue<int> iqueue;
queue<int> stl_queue;
PriorityQueue<int> ipqueue;
priority_queue<int> stl_pqueue;
Map<string,int> imap;
Map<int,int> imap2;
unordered_map<string,int> stl_map;
unordered_map<int,int> stl_map2;


void ListaTest() {
  int choice=0;
  int number=0;
  unsigned int index=0;
  int count=0;
  cout<<"Menu:"<<endl;
  cout<<"1. Dodaj element na poczatek listy"<<endl;
  cout<<"2. Dodaj element na koniec listy"<<endl;
  cout<<"3. Wyswietl elementy z listy"<<endl;
  cout<<"4. Dodaj element w wybrane miejsce"<<endl;
  cout<<"5. Usun element z poczatku listy"<<endl;
  cout<<"6. Usun element z konca listy"<<endl;
  cout<<"7. Usun wszystkie pola przechowujace wybrany element"<<endl;
  cout<<"8. Wyswietl element na podanym miejscu"<<endl;
  cout<<"9. Wyswietl menu"<<endl;
  cout<<"10. Zakoncz testy na liscie"<<endl;
  cout<<"11. Test iteratorow"<<endl;
  while(choice!=10){
    cout<<"Wybor:";
    cin>>choice;
    if (cin.fail() ) {    /*sprawdzenie czy udalo sie wczytac poprawnie*/
	cerr <<" Blad formatu wprowadzonej wartosci";
	cout <<" Operacja nie zostala wykonana"<<endl;
	cout <<endl;
	cin.clear();
	cin.ignore(10000,'\n'); } /*pomin znaki az do znaku konca lini*/
    else{
      switch(choice){
      case 1:
	cout<<"Element na przod"<<endl;
	cin>>number;
	if (cin.fail() ) {    /*sprawdzenie czy udalo sie wczytac poprawnie*/
	  cerr <<" Blad formatu wprowadzonej wartosci";
	  cout <<" Operacja nie zostala wykonana"<<endl;
	  cout <<endl;
	  cin.clear();
	  cin.ignore(10000,'\n'); } /*pomin znaki az do znaku konca lini*/
	else{
	  ilist.pushFront(number);
	  stl_list.push_front(number);}
	break;
      case 2:
	cout<<"Element na tyl"<<endl;
	cin>>number;
	if (cin.fail() ) {    /*sprawdzenie czy udalo sie wczytac poprawnie*/
	  cerr <<" Blad formatu wprowadzonej wartosci";
	  cout <<" Operacja nie zostala wykonana"<<endl;
	  cout <<endl;
	  cin.clear();
	  cin.ignore(10000,'\n'); } /*pomin znaki az do znaku konca lini*/
	else{
	  ilist.pushBack(number);
	  stl_list.push_back(number); }
	break;
      case 3:
	ilist.Display();
	cout<<"Zawartosc listy(STL):"<<endl;
	for (list<int>::iterator it=stl_list.begin();it!=stl_list.end();++it)
	  cout<<*it<<"   ";
	cout<<endl;
	count=std::count_if(ilist.begin(),ilist.end(),[](int i){return i>0;});
	cout<<"Liczba elementow w tablicy większych od zera:"<<count<<endl;
	break;
      case 4:
	cout<<"Liczba"<<endl;
	cin>>number;
	if (cin.fail() ) {    /*sprawdzenie czy udalo sie wczytac poprawnie*/
	  cerr <<" Blad formatu wprowadzonej wartosci";
	  cout <<" Operacja nie zostala wykonana"<<endl;
	  cout <<endl;
	  cin.clear();
	  cin.ignore(10000,'\n'); } /*pomin znaki az do znaku konca lini*/
	else{
	  cout<<"Index"<<endl;
	  cin>>index;
	  if (cin.fail() ) {    /*sprawdzenie czy udalo sie wczytac poprawnie*/
	    cerr <<" Blad formatu wprowadzonej wartosci";
	    cout <<" Operacja nie zostala wykonana"<<endl;
	    cout <<endl;
	    cin.clear();
	    cin.ignore(10000,'\n'); } /*pomin znaki az do znaku konca lini*/
	  else{
	    ilist.insert(number,index);
	    if (index>(stl_list.size()-1)) 
	      stl_list.insert(stl_list.end(),number);
	    else {
	      list<int>::iterator it=stl_list.begin();
	      for (unsigned int i=0;i<index;++i)
		++it;
	      stl_list.insert(it, number); }
	  }
	}
	break;
      case 5:
	if (ilist.isEmpty()) 
	  cout<<"Lista jest pusta. Wybierz inna operacje."<<endl;
	else {
	  number=ilist.popFront();
	  cout<<"Usunieto z przodu element:"<<number<<endl;
	  cout<<"Usunieto z przodu element(STL):"<<stl_list.front()<<endl;
	  stl_list.pop_front();
	}
	break;
      case 6:
	if (ilist.isEmpty()) 
	  cout<<"Lista jest pusta. Wybierz inna operacje."<<endl;
	else {
	  number=ilist.popBack();
	  cout<<"Usunieto z tylu element:"<<number<<endl;
	  cout<<"Usunieto z tylu element(STL):"<<stl_list.back()<<endl;
	  stl_list.pop_back();
	}
	break;
      case 7:
	if (ilist.isEmpty()) 
	  cout<<"Lista jest pusta. Wybierz inna operacje."<<endl;
	else {
	  cout<<"Element do usuniecia"<<endl;
	  cin>>number;
	  if (cin.fail() ) {    /*sprawdzenie czy udalo sie wczytac poprawnie*/
	    cerr <<" Blad formatu wprowadzonej wartosci";
	    cout <<" Operacja nie zostala wykonana"<<endl;
	    cout <<endl;
	    cin.clear();
	    cin.ignore(10000,'\n'); } /*pomin znaki az do znaku konca lini*/
	  else{
	    ilist.remove(number);
	    stl_list.remove(number);}
	}
	break;
      case 8:
	if (ilist.isEmpty()) 
	  cout<<"Lista jest pusta. Wybierz inna operacje."<<endl;
	else {
	  cout<<"Index liczby do wyswietlenia"<<endl;
	  cin>>index;
	  if (cin.fail() ) {    /*sprawdzenie czy udalo sie wczytac poprawnie*/
	    cerr <<" Blad formatu wprowadzonej wartosci";
	    cout <<" Operacja nie zostala wykonana"<<endl;
	    cout <<endl;
	    cin.clear();
	    cin.ignore(10000,'\n'); } /*pomin znaki az do znaku konca lini*/
	  else{
	    cout<<"Element pod podanym indexem:";
	    cout<<ilist[index]<<endl;
	    cout<<"Element pod podanym indexem(STL):";
	    if (index>(stl_list.size()-1)) 
	      cout<<*(stl_list.begin())<<endl;
	    else {
	      list<int>::iterator it=stl_list.begin();
	      for (unsigned int i=0;i<index;++i)
		++it;
	      cout<<*it<<endl;
	    }
	  }
	}
	break;
      case 9:
	cout<<"Menu:"<<endl;
	cout<<"1. Dodaj element na poczatek listy"<<endl;
	cout<<"2. Dodaj element na koniec listy"<<endl;
	cout<<"3. Wyswietl elementy z listy"<<endl;
	cout<<"4. Dodaj element w wybrane miejsce"<<endl;
	cout<<"5. Usun element z poczatku listy"<<endl;
	cout<<"6. Usun element z konca listy"<<endl;
	cout<<"7. Usun wszystkie pola przechowujace wybrany element"<<endl;
	cout<<"8. Wyswietl element na podanym miejscu"<<endl;
	cout<<"9. Wyswietl menu"<<endl;
	cout<<"10. Zakoncz testy na liscie"<<endl;
	cout<<"11. Test iteratorow(sprawdzenie poprawnosci metod listy zwiazanych z iteratorami)"<<endl;
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
    if (cin.fail() ) {    /*sprawdzenie czy udalo sie wczytac poprawnie*/
      cerr <<" Blad formatu wprowadzonej wartosci";
      cout <<" Operacja nie zostala wykonana"<<endl;
      cout <<endl;
      cin.clear();
      cin.ignore(10000,'\n'); } /*pomin znaki az do znaku konca lini*/
    else{
      switch(choice){
      case 1:
	cout<<"Dodawany element:"<<endl;
	cin>>number;
	if (cin.fail() ) {    /*sprawdzenie czy udalo sie wczytac poprawnie*/
	  cerr <<" Blad formatu wprowadzonej wartosci";
	  cout <<" Operacja nie zostala wykonana"<<endl;
	  cout <<endl;
	  cin.clear();
	  cin.ignore(10000,'\n'); } /*pomin znaki az do znaku konca lini*/
	else{
	  istack.push(number);
	  stl_stack.push(number); }
	break;
      case 2:
	if (istack.isEmpty()) 
	  cout<<"Stos jest pusty. Wybierz inna operacje."<<endl;
	else {
	  number=istack.pop();
	  cout<<"Sciagniety element:"<<number<<endl;
	  cout<<"Sciagniety element(STL):"<<stl_stack.top()<<endl;
	  stl_stack.pop();
	}
	break;
      case 3:
	istack.Display();
	if (stl_stack.empty())
	  cout<<"Stos STL jest pusty"<<endl;
	else
	  cout<<"Stos STL wyswietla tylko element na szczycie stosu:"<<stl_stack.top()<<endl;
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
    if (cin.fail() ) {    /*sprawdzenie czy udalo sie wczytac poprawnie*/
      cerr <<" Blad formatu wprowadzonej wartosci";
      cout <<" Operacja nie zostala wykonana"<<endl;
      cout <<endl;
      cin.clear();
      cin.ignore(10000,'\n'); } /*pomin znaki az do znaku konca lini*/
    else{
      switch(choice){
      case 1:
	cout<<"Dodawany element:"<<endl;
	cin>>number;
	if (cin.fail() ) {    /*sprawdzenie czy udalo sie wczytac poprawnie*/
	  cerr <<" Blad formatu wprowadzonej wartosci";
	  cout <<" Operacja nie zostala wykonana"<<endl;
	  cout <<endl;
	  cin.clear();
	  cin.ignore(10000,'\n'); } /*pomin znaki az do znaku konca lini*/
	else{
	  iqueue.enqueue(number);
	  stl_queue.push(number);}
	break;
      case 2:
	if (iqueue.isEmpty()) 
	  cout<<"Kolejka jest pusta. Wybierz inna operacje."<<endl;
	else {
	  number=iqueue.dequeue();
	  cout<<"Sciagniety element:"<<number<<endl;
	  cout<<"Sciagniety element(STL):"<<stl_queue.front()<<endl;
	  stl_queue.pop();
	}
	break;
      case 3:
	iqueue.Display();
	if (stl_queue.empty())
	  cout<<"Kolejka STL jest pusta"<<endl;
	else {
	  cout<<"Kolejka STL wyswietla tylko pierwszy i ostatni element"<<endl;
	  cout<<"Pierwszy:"<<stl_queue.front()<<"   "<<"Ostatni:"<<stl_queue.back()<<endl; }
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
}

void PriorityQueueTest() {
  int choice=0;
  int number=0;
  int prior=0;
  cout<<"Kolejka priorytetowa STL przechowuje tylko priorytet."<<endl;
  cout<<"Nie przechowuje elementu, aby zachowac te sama kolejnosc w obu kolejkach."<<endl;
  cout<<"Menu:"<<endl;
  cout<<"1. Dodaj element do kolejki priorytetowej"<<endl;
  cout<<"2. Sciagnij element z kolejki"<<endl;
  cout<<"3. Wyswietl elementy w kolejce wraz z ich priorytetami"<<endl;
  cout<<"4. Wyswietl menu"<<endl;
  cout<<"5. Zakoncz testy na kolejce priorytetowej"<<endl;
  while(choice!=5){
    cout<<"Wybor:";
    cin>>choice;
    if (cin.fail() ) {    /*sprawdzenie czy udalo sie wczytac poprawnie*/
      cerr <<" Blad formatu wprowadzonej wartosci";
      cout <<" Operacja nie zostala wykonana"<<endl;
      cout <<endl;
      cin.clear();
      cin.ignore(10000,'\n'); } /*pomin znaki az do znaku konca lini*/
    else{
      switch(choice){
      case 1:
	cout<<"Dodawany element:"<<endl;
	cin>>number;
	if (cin.fail() ) {    /*sprawdzenie czy udalo sie wczytac poprawnie*/
	  cerr <<" Blad formatu wprowadzonej wartosci";
	  cout <<" Operacja nie zostala wykonana"<<endl;
	  cout <<endl;
	  cin.clear();
	  cin.ignore(10000,'\n'); } /*pomin znaki az do znaku konca lini*/
	else{
	  cout<<"Priorytet dodawanego elementy:"<<endl;
	  cin>>prior;
	  if (cin.fail() ) {    /*sprawdzenie czy udalo sie wczytac poprawnie*/
	    cerr <<" Blad formatu wprowadzonej wartosci";
	    cout <<" Operacja nie zostala wykonana"<<endl;
	    cout <<endl;
	    cin.clear();
	    cin.ignore(10000,'\n'); } /*pomin znaki az do znaku konca lini*/
	  else{
	    ipqueue.enqueue(number,prior);
	    stl_pqueue.push(prior);
	  }
	}
	break;
      case 2:
	if (ipqueue.isEmpty()) 
	  cout<<"Kolejka jest pusta. Wybierz inna operacje."<<endl;
	else {
	  number=ipqueue.dequeue();
	  cout<<"Sciagniety element:"<<number<<endl;
	  cout<<"Sciagniety priorytet(STL):"<<stl_pqueue.top()<<endl;
	  stl_pqueue.pop();
	}
	break;
      case 3:
	ipqueue.Display();
	if (stl_pqueue.empty())
	  cout<<"Kolejka priorytetowa STL jest pusta"<<endl;
	else {
	  cout<<"Kolejka priorytetowa STL wyswielta tylko najwyzszy priorytet"<<endl;
	  cout<<stl_pqueue.top()<<endl; }
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
}

void MapTestS() {
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
    if (cin.fail() ) {    /*sprawdzenie czy udalo sie wczytac poprawnie*/
      cerr <<" Blad formatu wprowadzonej wartosci";
      cout <<" Operacja nie zostala wykonana"<<endl;
      cout <<endl;
      cin.clear();
      cin.ignore(10000,'\n'); } /*pomin znaki az do znaku konca lini*/
    else{
      switch(choice){
      case 1:
	cout<<"Podaj klucz:"<<endl;
	cin>>key;
	if (cin.fail() ) {    /*sprawdzenie czy udalo sie wczytac poprawnie*/
	  cerr <<" Blad formatu wprowadzonej wartosci";
	  cout <<" Operacja nie zostala wykonana"<<endl;
	  cout <<endl;
	  cin.clear();
	  cin.ignore(10000,'\n'); } /*pomin znaki az do znaku konca lini*/
	else{
	  cout<<"Podaj jego wartosc:"<<endl;
	  cin>>number;
	  if (cin.fail() ) {    /*sprawdzenie czy udalo sie wczytac poprawnie*/
	    cerr <<" Blad formatu wprowadzonej wartosci";
	    cout <<" Operacja nie zostala wykonana"<<endl;
	    cout <<endl;
	    cin.clear();
	    cin.ignore(10000,'\n'); } /*pomin znaki az do znaku konca lini*/
	  else{
	    imap.insert(key,number);
	    stl_map[key]=number; }
	}
	break;
      case 2:
	cout<<"Podaj klucz:"<<endl;
	cin>>key;
	if (cin.fail() ) {    /*sprawdzenie czy udalo sie wczytac poprawnie*/
	  cerr <<" Blad formatu wprowadzonej wartosci";
	  cout <<" Operacja nie zostala wykonana"<<endl;
	  cout <<endl;
	  cin.clear();
	  cin.ignore(10000,'\n'); } /*pomin znaki az do znaku konca lini*/
	else{
	  number=imap[key];
	  if (number==0)
	    cout<<"Podany klucz nie zostal wczesniej wprowadzony do tablicy"<<endl;
	  else
	    cout<<"Wartosc wprowadzonego klucza: "<<number<<endl;
	  number=stl_map[key];
	  cout<<"Wartosc wprowadzonego klucza(STL): "<<number<<endl;
	}
	break;
      case 3:
	cout<<"Podaj klucz ktorego wartosc chcesz usunac z tablicy"<<endl;
	cin>>key;
	if (cin.fail() ) {    /*sprawdzenie czy udalo sie wczytac poprawnie*/
	  cerr <<" Blad formatu wprowadzonej wartosci";
	  cout <<" Operacja nie zostala wykonana"<<endl;
	  cout <<endl;
	  cin.clear();
	  cin.ignore(10000,'\n'); } /*pomin znaki az do znaku konca lini*/
	else{
	  imap.remove(key);
	  stl_map.erase(key); }
	break;
      case 4:
	cout<<"Zawartosc tablicy";
	imap.Display();
	cout<<"Zawartosc tablicy wraz z kluczami(STL):"<<endl;
	for (auto x : stl_map)
	  cout<<x.first<<"  "<<x.second<<endl;
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
}

void MapTestI() {
  int choice=0;
  int number=0;
  int key=0;
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
    if (cin.fail() ) {    /*sprawdzenie czy udalo sie wczytac poprawnie*/
      cerr <<" Blad formatu wprowadzonej wartosci";
      cout <<" Operacja nie zostala wykonana"<<endl;
      cout <<endl;
      cin.clear();
      cin.ignore(10000,'\n'); } /*pomin znaki az do znaku konca lini*/
    else{
      switch(choice){
      case 1:
	cout<<"Podaj klucz:"<<endl;
	cin>>key;
	if (cin.fail() ) {    /*sprawdzenie czy udalo sie wczytac poprawnie*/
	  cerr <<" Blad formatu wprowadzonej wartosci";
	  cout <<" Operacja nie zostala wykonana"<<endl;
	  cout <<endl;
	  cin.clear();
	  cin.ignore(10000,'\n'); } /*pomin znaki az do znaku konca lini*/
	else{
	  cout<<"Podaj jego wartosc:"<<endl;
	  cin>>number;
	  if (cin.fail() ) {    /*sprawdzenie czy udalo sie wczytac poprawnie*/
	    cerr <<" Blad formatu wprowadzonej wartosci";
	    cout <<" Operacja nie zostala wykonana"<<endl;
	    cout <<endl;
	    cin.clear();
	    cin.ignore(10000,'\n'); } /*pomin znaki az do znaku konca lini*/
	  else{
	    imap2.insert(key,number);
	    stl_map2[key]=number; }
	}
	break;
      case 2:
	cout<<"Podaj klucz:"<<endl;
	cin>>key;
	if (cin.fail() ) {    /*sprawdzenie czy udalo sie wczytac poprawnie*/
	  cerr <<" Blad formatu wprowadzonej wartosci";
	  cout <<" Operacja nie zostala wykonana"<<endl;
	  cout <<endl;
	  cin.clear();
	  cin.ignore(10000,'\n'); } /*pomin znaki az do znaku konca lini*/
	else{
	  number=imap2[key];
	  if (number==0)
	    cout<<"Podany klucz nie zostal wczesniej wprowadzony do tablicy"<<endl;
	  else
	    cout<<"Wartosc wprowadzonego klucza: "<<number<<endl;
	  number=stl_map2[key];
	  cout<<"Wartosc wprowadzonego klucza(STL): "<<number<<endl; }
	break;
      case 3:
	cout<<"Podaj klucz ktorego wartosc chcesz usunac z tablicy"<<endl;
	cin>>key;
	if (cin.fail() ) {    /*sprawdzenie czy udalo sie wczytac poprawnie*/
	  cerr <<" Blad formatu wprowadzonej wartosci";
	  cout <<" Operacja nie zostala wykonana"<<endl;
	  cout <<endl;
	  cin.clear();
	  cin.ignore(10000,'\n'); } /*pomin znaki az do znaku konca lini*/
	else{
	  imap2.remove(key);
	  stl_map2.erase(key); }
	break;
      case 4:
	cout<<"Zawartosc tablicy";
	imap2.Display();
	cout<<"Zawartosc tablicy wraz z kluczami(STL):"<<endl;
	for (auto x : stl_map2)
	  cout<<x.first<<"  "<<x.second<<endl;
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
}

int main() {
  int mchoice=0;
  while (mchoice!=7) {
    cout<<"Wybierz strukture do testowania"<<endl;
    cout<<"1. Lista"<<endl;
    cout<<"2. Stos"<<endl;
    cout<<"3. Kolejka"<<endl;
    cout<<"4. Kolejka priorytetowa"<<endl;
    cout<<"5. Tablica z hashowaniem(klucz string)"<<endl;
    cout<<"6. Tablica z hashowaniem(klucz int)"<<endl;
    cout<<"7. Zakoncz dzialanie programu"<<endl;
    cin>>mchoice;
    if (cin.fail() ) {    /*sprawdzenie czy udalo sie wczytac poprawnie*/
      cerr <<" Blad formatu wprowadzonej wartosci";
      cout <<" Operacja nie zostala wykonana"<<endl;
      cout <<endl;
      cin.clear();
      cin.ignore(10000,'\n'); } /*pomin znaki az do znaku konca lini*/
    else{
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
	MapTestS();
	break;
      case 6:
	MapTestI();
	break;
      case 7:
	cout<<"Zakonczono dzialanie programu"<<endl;
	break;
      default:
	cout<<"Wybrano nieistniejaca opcje. Sprobuj ponownie"<<endl;
	break;
      }
    }
  }
  return 0;
}
