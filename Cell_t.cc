#include "Cell_t.h"

Cell_t::Cell_t(int i, int j, bool alive)
{
    position_.first = i;
    position_.second = j;
    state_ = alive;
}
int Cell_t::countingNeighbours(Board_t &board_var)
{
}

bool Cell_t::updateState(Board_t &board_var)
{
}

std::ostream &Cell_t::printCell(std::ostream &os)
{
    state_ ? os << "#" : os << "N";
}

void Cell_t::deleteCell(){
    delete this;
}

Cell_t::~Cell_t()
{
    deleteCell();
}