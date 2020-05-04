#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>


class GraphBase {
 public:
  int V;
  virtual void addEdge(int u, int v, int weight) = 0;
  virtual bool deleteEdge(int u, int v) = 0;
  virtual std::vector<int> neighbours(int u) = 0;
  virtual int weight(int u, int v) = 0;
};

