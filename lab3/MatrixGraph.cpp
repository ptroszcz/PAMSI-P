#include "MatrixGraph.hh"

void MatrixGraph::addEdge(int u, int v, int weight){
  adjacencyMatrix(u, v) = weight;
}

bool MatrixGraph::deleteEdge(int u, int v) {
  if (adjacencyMatrix(u, v)==std::numeric_limits<int>::min())
    return false;
  else {
    adjacencyMatrix(u, v) = std::numeric_limits<int>::min();
    return true;
  }
}

std::vector<int> MatrixGraph::neighbours(int u) {
  std::vector<int> neighboursVec;
  for(int i = 0; i < V; ++i) {
    if( adjacencyMatrix(u, i)!= std::numeric_limits<int>::min())
      neighboursVec.push_back(i);
  }
  return neighboursVec;
}

int MatrixGraph::weight(int u, int v) {
  return adjacencyMatrix(u,v);
}

void MatrixGraph::Display() {
  for (int i=0;i<V;++i) {
    for (int j=0;j<V;++j) {
      if (i==j || adjacencyMatrix(i,j)==std::numeric_limits<int>::min())
	std::cout<<"--  ";
      else
	std::cout<<adjacencyMatrix(i,j)<<"  ";
    }
    std::cout<<std::endl;
  }
}
