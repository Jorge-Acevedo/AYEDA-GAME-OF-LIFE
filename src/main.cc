#include "../inc/Cell_t.h"
#include <assert.h>
void gameOfLife(Board_t board, unsigned int turns)
{
  std::cout << "INITIAL STATE: " << std::endl;
  board.printBoard(std::cout);
  std::cout << "PRESIONE ENTER PARA PASAR DE TURNO!" << std::endl;
  std::cin.get();
  for (int i = 1; i <= turns; i++)
  {
    std::cout << "TURN: " << i << std::endl;
    board.newTurn();
    std::cin.get();
  }
}

void setInitialState()
{
  int numberOfCells, numberOfTurns, width, heigth, x, y;

  std::cout << "Width of the board: ";
  std::cin >> width;
  assert(width > 0);

  std::cout << "Heigth of the board: ";
  std::cin >> heigth;
  assert(heigth > 0);

  Board_t board(width, heigth);

  std::cout << "Number of turns you expect to play: ";
  std::cin >> numberOfTurns;
  assert(numberOfTurns > 0);

  std::cout << "Number of alive cells at initial state: ";
  std::cin >> numberOfCells;
  assert(numberOfCells > 0);

  for (int i = 0; i < numberOfCells; i++)
  {
    std::cout << "Cell " << i << ":\n";
    std::cout << "X axis: ";
    std::cin >> x;
    assert(x > 0 && x <= width);
    std::cout << "Y axis: ";
    std::cin >> y;
    assert(y > 0 && y <= width);
    board.getCell(x, y)->setState(1);
  }
  gameOfLife(board, numberOfTurns);
}

int main(void)
{
  setInitialState();
}
