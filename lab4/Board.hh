#pragma once

#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstdlib>
#include <climits>

class MoveCo {
public:
  int x1;
  int y1;
  int x2;
  int y2;
  MoveCo(int _x1, int _y1, int _x2, int _y2) {
    x1=_x1;
    y1=_y1;
    x2=_x2;
    y2=_y2;
  }
};



class Path {
public:
  std::vector<MoveCo> pathvec;
  bool Capture;
  void Display();
};


class Matrix
{
  public:
    Matrix(int n, int m, int defaultValue = std::numeric_limits<int>::min()) : ncols{n} { vec.resize(n * m, defaultValue); }

    int& operator()(int x, int y) { return vec[x * ncols + y]; }

  private:
    std::vector<int> vec;
    int ncols;
};


class Board {
  Matrix board;

public:
  Board():board(8,8) {
    init();
  }
  int& operator()(int x, int y) {
    return board(x,y);}
  void init();
  bool MoveBlack(int x1, int y1, int x2, int y2);
  bool MoveWhite(int x1, int y1, int x2, int y2);
  bool CheckCaptureBlack(int x, int y);
  bool CheckCaptureWhite(int x, int y);
  bool CheckCaptureBlack(int x1, int y1, int x2, int y2);
  bool CheckCaptureWhite(int x1, int y1, int x2, int y2);
  bool AnyCaptureWhite();
  bool AnyCaptureBlack();
  bool CaptureBlack(int x1, int y1, int x2, int y2);
  bool CaptureWhite(int x1, int y1, int x2, int y2);
  void BackBoard(std::vector<std::vector<int>> back);
  std::vector<std::vector<int>> CaptureCopy(int x1, int y1, int x2, int y2);
  std::vector<std::vector<int>> PossibleBlackCapture(int i, int j);
  std::vector<std::vector<int>> PossibleWhiteCapture(int i, int j);
  std::vector<Path> MultipleCaptureBlack(int x, int y);
  std::vector<Path> MultipleCaptureWhite(int x, int y);
  std::vector<Path> PossibleBlack();
  std::vector<Path> PossibleWhite();
  std::vector<std::vector<int>> Move(Path road, bool white);
  int Calculate();
};
