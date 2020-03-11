#include "../inc/Board_t.h"

Board_t::Board_t(int rows, int cols)
{
  //El +2 es para evitar acceder a posiciones no existentes en otros métodos
  turn_ = 0;
  rows_ = rows;
  cols_ = cols;
  cellArray_.resize(rows_ + 2);
  for (int i = 0; i < rows_ + 2; i++)
  {
    cellArray_[i].resize(cols_ + 2);
    for (int j = 0; j < cols_ + 2; j++)
    {
      cellArray_[i][j] = new Cell_t(i, j, 0);
    }
  }
}

std::ostream &Board_t::printBoard(std::ostream &os)
{
  for (int i = 1; i <= rows_; i++)
  {
    for (int j = 1; j <= cols_; j++)
    {
      cellArray_[i][j]->printCell(os);
    }
    std::cout << "\n";
  }
}

Board_t::~Board_t()
{
  deleteBoard();
}

void Board_t::deleteBoard()
{
  for (int i = 0; i < rows_; i++)
  {
    for (int j = 0; j < cols_; j++)
    {
      delete (cellArray_[i][j]);
    }
  }
}

void Board_t::newTurn()
{
  for (int i = 1; i <= rows_; i++)
  {
    for (int j = 1; j <= cols_; j++)
    {
      cellArray_[i][j]->countingNeighbours(*this);
    }
  }

  for (int i = 1; i <= rows_; i++)
  {
    for (int j = 1; j <= cols_; j++)
    {
      cellArray_[i][j]->updateState();
    }
  }
  printBoard(std::cout);
  turn_++;
}