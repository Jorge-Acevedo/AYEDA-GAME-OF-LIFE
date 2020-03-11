#pragma once
#include "Cell_t.h"

class Cell_t;

class Board_t
{
private:
  int rows_;
  int cols_;
  unsigned int turn_;
  std::vector<std::vector<Cell_t *> > cellArray_;

public:
  Board_t(int rows, int cols);
  ~Board_t();
  // Setters
  inline void setRows(int n) { rows_ = n; }
  inline void setCols(int m) { cols_ = m; }
  // Getterss
  inline int getRows() { return rows_; }
  inline int getCols() { return cols_; }

  //output
  std::ostream &printBoard(std::ostream &os);
  void deleteBoard();
  void newTurn();
  inline Cell_t* getCell(int i, int j) const { return cellArray_[i][j];}
};