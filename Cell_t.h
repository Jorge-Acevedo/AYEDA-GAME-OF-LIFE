#pragma once

#include <iostream>
#include <utility>
#include <vector>

#include "Board_t.h"

class Board_t;

class Cell_t
{
  private:
    bool state_;
    std::pair<int, int> position_;
  public:
    Cell_t(int i = 0, int j = 0, bool alive = 0);
    ~Cell_t();
    // Method that allows obtain the value of atribute "state_"
    int getState() const;
    // Method that allows set the value of atribute "state_"
    int setState(int);
    bool updateState(Board_t& board_var);
    int countingNeighbours(Board_t& board_var);
    void deleteCell();
    std::ostream& printCell(std::ostream& os);
};