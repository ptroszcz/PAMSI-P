#pragma once

#include "GraphBase.hh"


class ListGraph : public GraphBase
{
  struct Adjacency
  {
    int v;
    int weight;
  };

  using AdjacencyList = std::vector<Adjacency>;
  std::vector<AdjacencyList> adjecancyList;
  
  public:

  ListGraph(int numOfVertices) {
    adjecancyList.resize(numOfVertices);
    V=numOfVertices; }
  virtual void addEdge(int u, int v, int weight);
  virtual bool deleteEdge(int u, int v);
  virtual std::vector<int> neighbours(int u);
  virtual int weight(int u, int v);
  void Display();
};
