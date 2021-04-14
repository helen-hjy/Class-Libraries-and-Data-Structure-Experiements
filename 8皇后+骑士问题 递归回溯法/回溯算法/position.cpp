

#include "position.h"

Position::Position()
{
	row = 0;
	column = 0;
}

Position::Position(int thisRow, int thisCol)
{
	row = thisRow;
	column = thisCol;
}

int Position::getRow()
{
	return row;
}

int Position::getColumn()
{
	return column;
}