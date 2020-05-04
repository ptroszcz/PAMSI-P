#include <vector>
#include <climits>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <fstream>
#include <iomanip>
#include "PriorityQueue.hh"
#include "ListGraph.hh"
#include "MatrixGraph.hh"
#include "dijkstra.hh"





int main() {
  srand(time(NULL));
  std::chrono::high_resolution_clock timer;
  int size=500;
  int number_of_graphs=100;
  int first=0;
  int graph_density=25;
  //std::vector<ListGraph> graphs;
  std::vector<MatrixGraph> graphs;

  for (int k=0;k<number_of_graphs;++k) {
    //ListGraph graph(size);
    MatrixGraph graph(size);
    for (int i=0;i<size;++i) {
      for (int j=0;j<size;++j){
	if (i!=j)
	graph.addEdge(i,j,(rand()%100)+1);
      }
    }
    /*aby zapewnić grafom pewność, że po usunięciu krawędzi nadal będzie możliwe
      dostanie się do każdego wiechołka z dowolnego innego wierzchołka nie usuwane są
      połączenia między ostatnim wierzchołkiem a innymi*/
    if (graph_density<100){ 
      int deletenumber=((100-graph_density)*graph.V*(graph.V-1))/100;
      while (deletenumber>0) {
	while((graph.deleteEdge(rand()%(graph.V-1),rand()%(graph.V-1)))==false){}
	//jezeli wylosuje 2 razy ta sama krawedz do usuniecia to powtorzy losowanie
	deletenumber--;  
      }
    }
    graphs.push_back(graph);
  }
  double fulltime=0;
  for (unsigned int i=0;i<graphs.size();i++) {
    auto tstart=timer.now();
    dijkstra(graphs[i],first);
    auto tend=timer.now();
    std::chrono::duration<double> sec=tend-tstart;
    fulltime+=sec.count();
  }
  std::cout<<"Czas wykonywania algorytmu dla 100 instancji grafu: " <<fulltime<<"s"<<std::endl;
  std::cout<<"Sredni czas wykonywania algorytmu dla jednego grafu: "<<(fulltime/number_of_graphs)*1000<<"ms"<<std::endl;

  /*ponizej przyklad wczytania grafu z pliku tekstowego oraz zapisania jego wynikow dzialania do pliku
    powyzsze badania dla 100 instancji nie sa zapisywane do pliku, poniewaz spowodowalo by to duze 
    spowolnienie dzialania programu, dlatego mierzony jest zaledwie czas wykonywania algorytmu
    i wyswietlany na standardowym wyjsciu, dlatego ponizej sa ukazane procesy wczytania grafu i zapisu
    wynikow dzialania algorytmu na nim w celu ukazania zaimplementowania tych dwoch operacji*/

  //wczytywanie grafu z pliku
  std::ifstream gfile;
  gfile.open("example_graph.txt");
  if(!gfile.good())
    std::cerr<<"Can't open a file"<<std::endl;
  int a=0,b=0,c=0;
  int number_of_edge=0;
  gfile>>number_of_edge;
  gfile>>size;
  gfile>>first;
  //ListGraph graph(size);           //wybór rodzaju reprezentacji grafu
  MatrixGraph graph(size);
  while(number_of_edge>0) {
    gfile>>a;
    gfile>>b;
    gfile>>c;
    graph.addEdge(a,b,c);
    number_of_edge--;
  }
  gfile.close();
  
  //wyswietlenie grafu w celu sprawdzenia poprawnego wczytania pliku
  std::cout<<"Wyswietlenie grafu wczytanego z pliku 'example_graph.txt':"<<std::endl;
  graph.Display();
  
  std::vector<std::vector<int>> test=dijkstra(graph,first);
  //zapis wynikow to pliku
  std::ofstream rfile("results.txt");
  rfile<<"Wyniki dzialania algorytmu dijkstry dla danego grafu."<<std::endl;
  rfile<<"Kazda kolejna linia okresla droge to kolejnych wierzcholkow."<<std::endl;
  rfile<<"Oznacza to, ze pierwsze dane okreslaja droge do wierzcholka 0, nastepne do wiecholka 1 itd. Format:";
  rfile<<std::endl<<"KOSZT_DROGI   CIAG_WIERZCHOLKOW_OD_WIERZCHOLKA_POCZATKOWEGO"<<std::endl;
  int tab[1000];  //poniewaz maksymalnie nalezy pokonac tyle wierzcholkow ile ma graf
                                   
  for (int i=0;i<graph.V;++i) {
    rfile<<std::setw(5)<<test[i][0];
    if (i==first)
      rfile<<"    To jest wierzcholek poczatkowy"<<std::endl;
    else {
      int k=0;
      tab[k]=test[i][1];
      while (tab[k]!=first) {
	tab[k+1]=test[tab[k]][1];
	k++;
      }
      while (k>=0) {
	rfile<<std::setw(5)<<tab[k];
	k--;}
      rfile<<std::setw(5)<<i<<std::endl;
    }
  }
  rfile.close();
  
  return 0;
}
