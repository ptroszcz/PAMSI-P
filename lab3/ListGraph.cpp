#include "ListGraph.hh"

void ListGraph::addEdge(int u, int v, int weight){
  Adjacency adj{v, weight};
  adjecancyList[u].push_back(adj);
}

bool ListGraph::deleteEdge(int u, int v){
  auto& adjList = adjecancyList[u];
  auto it = std::find_if(adjList.begin(), adjList.end(), [v](const Adjacency& adj) { return v == adj.v; });
  if(adjList.end() != it) {
    std::swap(*it,*(adjList.end()-1));
    adjList.pop_back();
    return true;
  }
  else
    return false;
    
  /* std::remove_if(adjList.begin(), adjList.end(), [v](const Adjacency& adj){
      return adj.v == v;
      });*/
}

std::vector<int> ListGraph::neighbours(int u){
  std::vector<int> neighboursVec;
  auto& adjList = adjecancyList[u]; 
  std::transform(adjList.begin(), adjList.end(), std::back_inserter(neighboursVec),[](const Adjacency& adj) { return adj.v; });
  return neighboursVec;
}

int ListGraph::weight(int u, int v){
  auto& adjList = adjecancyList[u];
  auto it = std::find_if(adjList.begin(), adjList.end(), [v](const Adjacency& adj) { return v == adj.v; });
  if(adjList.end() == it)
    throw std::runtime_error("Not found (u,v) edge");
  return it->weight;
}

void ListGraph::Display() {
  for (unsigned int i=0;i<adjecancyList.size();++i) {
    if (adjecancyList[i].size()!=0) {
      for (unsigned int j=0;j<adjecancyList[i].size();++j)
	std::cout<<"("<<adjecancyList[i][j].v<<","<<adjecancyList[i][j].weight<<")   ";
      std::cout<<std::endl;
    }
  }
}
