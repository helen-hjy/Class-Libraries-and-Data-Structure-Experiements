#ifndef POSITION_H
#define POSITION_H

class Position
{
public:
	Position();
	Position(int thisRow, int thisCol);
	int getRow();
	int getColumn();
private:
	int row;
	int column;
};


#endif
