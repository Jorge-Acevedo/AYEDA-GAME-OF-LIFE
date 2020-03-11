#pragma once

#include <iostream>
#include <utility>
#include <vector>

#include "Board_t.h"

class Board_t;

class Cell_t
{
private:
  int state_;
  int nextState_;
  std::pair<int, int> position_;

public:
  Cell_t(int i = 0, int j = 0, int alive = 0);
  ~Cell_t() {}
  inline int getState() const { return state_; }
  int setState(int);
  int updateState();
  int countingNeighbours(const Board_t &board_var);
  std::ostream &printCell(std::ostream &os);
};