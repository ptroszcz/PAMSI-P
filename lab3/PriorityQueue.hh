#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class PriorityQueue {
  std::vector<std::vector<int>> elem;
public:
  bool isEmpty();
  void push(std::vector<int> elem);
  std::vector<int> pop();
  void decrease_priority(int number, int npriority);
};
