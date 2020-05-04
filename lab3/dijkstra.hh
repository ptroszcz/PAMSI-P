#pragma once

#include <iostream>
#include <climits>
#include "PriorityQueue.hh"
#include "GraphBase.hh"



std::vector<std::vector<int>> dijkstra(GraphBase& graph, int u) {
  std::vector<std::vector<int>> result;
  std::vector<int> distance(graph.V);
  std::vector<int> previous(graph.V);
  std::vector<int> help(2);
  PriorityQueue Q;
  for (int i=0;i<graph.V;++i){
    if (u==i) 
      distance[i]=0;
    else 
      distance[i]=INT_MAX;
    previous[i]=std::numeric_limits<int>::min();
    help[0]=i;
    help[1]=distance[i];
    Q.push(help);
  }
  while (!Q.isEmpty()) {
    help=Q.pop();
    std::vector<int> neighbours = graph.neighbours(help[0]);
    for (unsigned int i=0;i<neighbours.size();++i) {
      int alt=distance[help[0]]+graph.weight(help[0],neighbours[i]);
      if (distance[neighbours[i]]>alt){
	distance[neighbours[i]]=alt;
	previous[neighbours[i]]=help[0];
	Q.decrease_priority(neighbours[i],alt);
      }
    }
  }
  for (int i=0;i<graph.V;i++) {
    help[0]=distance[i];
    help[1]=previous[i];
    result.push_back(help);
  }
  return result;
}
