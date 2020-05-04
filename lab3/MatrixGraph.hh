#pragma once

#include "GraphBase.hh"


class Matrix
{
  public:
    Matrix(int n, int m, int defaultValue = std::numeric_limits<int>::min()) : ncols{n} { vec.resize(n * m, defaultValue); }

    int& operator()(int x, int y) { return vec[x * ncols + y]; }

  private:
    std::vector<int> vec;
    int ncols;
};

class MatrixGraph : public GraphBase
{
  
  Matrix adjacencyMatrix;

public:
  MatrixGraph(int numOfVertices): adjacencyMatrix(numOfVertices,numOfVertices) {
    V=numOfVertices; }
  virtual void addEdge(int u, int v, int weight);
  virtual bool deleteEdge(int u, int v);
  virtual std::vector<int> neighbours(int u);
  virtual int weight(int u, int v);
  void Display();
};
