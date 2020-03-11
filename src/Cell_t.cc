#include "../inc/Cell_t.h"

Cell_t::Cell_t(int i, int j, int alive)
{
  position_.first = i;
  position_.second = j;
  state_ = alive;
}
int Cell_t::countingNeighbours(const Board_t &board_var)
{
  unsigned int aliveCounter = 0;

  //std::cout << "\nTratando de acceder a pos: (" << position_.first - 1 << ", " << position_.second - 1 << ")" << std::endl;
  (board_var.getCell(position_.first - 1, position_.second - 1)->getState() == 1) ? aliveCounter++ : aliveCounter;
  //std::cout << "\nTratando de acceder a pos: (" << position_.first - 1 << ", " << position_.second << ")" << std::endl;
  (board_var.getCell(position_.first - 1, position_.second)->getState() == 1) ? aliveCounter++ : aliveCounter;
  //std::cout << "\nTratando de acceder a pos: (" << position_.first - 1 << ", " << position_.second + 1 << ")" << std::endl;
  (board_var.getCell(position_.first - 1, position_.second + 1)->getState() == 1) ? aliveCounter++ : aliveCounter;
  //std::cout << "\nTratando de acceder a pos: (" << position_.first << ", " << position_.second - 1 << ")" << std::endl;
  (board_var.getCell(position_.first, position_.second - 1)->getState() == 1) ? aliveCounter++ : aliveCounter;
  //std::cout << "\nTratando de acceder a pos: (" << position_.first << ", " << position_.second + 1 << ")" << std::endl;
  (board_var.getCell(position_.first, position_.second + 1)->getState() == 1) ? aliveCounter++ : aliveCounter;
  //std::cout << "\nTratando de acceder a pos: (" << position_.first + 1 << ", " << position_.second - 1 << ")" << std::endl;
  (board_var.getCell(position_.first + 1, position_.second - 1)->getState() == 1) ? aliveCounter++ : aliveCounter;
  //std::cout << "\nTratando de acceder a pos: (" << position_.first + 1 << ", " << position_.second << ")" << std::endl;
  (board_var.getCell(position_.first + 1, position_.second)->getState() == 1) ? aliveCounter++ : aliveCounter;
  //std::cout << "\nTratando de acceder a pos: (" << position_.first + 1 << ", " << position_.second + 1 << ")" << std::endl;
  (board_var.getCell(position_.first + 1, position_.second + 1)->getState() == 1) ? aliveCounter++ : aliveCounter;

  //std::cout << "Number of adyacent living cells: " << aliveCounter << std::endl;
  if (state_ == 0)
    aliveCounter == 3 ? nextState_ = 1: nextState_ = 0;
  else 
    ((aliveCounter == 2) || (aliveCounter == 3)) ? nextState_ = 1: nextState_ = 0;
  return aliveCounter;
}

int Cell_t::updateState()
{
  state_ = nextState_;
}

std::ostream &Cell_t::printCell(std::ostream &os)
{
  state_ ? os << " X " : os << " - ";
}

int Cell_t::setState(int newState)
{
  if (newState == (0 || 1))
  {
    state_ = newState;
    return state_;
  }
  else
  {
    std::cout << "\nNon-existent state: " << newState << std::endl;
    return newState;
  }
}
