#include "Board_t.h"

Board_t::Board_t(int rows, int cols)
{
  rows_ = rows;
  cols_ = cols;
  cellArray_.resize(rows_);
  std::cout << "nºfilas: " << cellArray_.size() << std::endl;

  for (int i = 0; i < cols_; i++)
  {
    std::cout << "\n" << i << "\n";
    cellArray_[i].resize(cols_);
      std::cout.flush();
    for (int j = 0; j < rows; j++)
    {
      cellArray_[i][j] = new Cell_t(i, j, 0);
      cellArray_[i][j]->printCell(std::cout);
      std::cout.flush();
    }
    std::cout << "\n";
  }
}

std::ostream &Board_t::printBoard(std::ostream &os)
{
  for (int i = 0; i < cols_; i++)
  {
    for (int j = 0; j < rows_; j++)
    {
      cellArray_[i][j]->printCell(os);
    }
  }
}

Board_t::~Board_t()
{
  deleteBoard();
}

void Board_t::deleteBoard()
{
  for (int i = 0; i < cols_; i++)
  {
    for (int j = 0; j < rows_; j++)
    {
      cellArray_[i][j]->deleteCell();
    }
  }
}