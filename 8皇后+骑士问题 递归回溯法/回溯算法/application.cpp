
#include "application.h"
#include <iostream>
using namespace std;

//board
const int SIZE = 8;
int board[SIZE][SIZE];
int n=1;
void Application::initialize()
{
	
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			board[i][j] = 0;

}

Position Application::getStartPosition()
{
	int row,column;
	cout<<"Please input a start position\n";
	cout<<"Row:";  cin>>row;
	cout<<"Column:";  cin>>column;
	board[row][column]=n;

	return Position(row,column);
}


bool Application::isValid(Position p)
{
	int row=p.getRow();
	int column=p.getColumn();
	 if(row>=0&&row<SIZE&&column>=0&&column<SIZE&&board[row][column]==0)
	    return true;

	 return false;
}


void Application::extend(Position p)
{
	board[p.getRow()][p.getColumn()]=n;
}

bool Application::success(Position p)
{
	if(board[p.getRow()][p.getColumn()] == 64)
	   return true;
	return false;
}

void Application::goBack(Position p)
{
	board[p.getRow()][p.getColumn()] = 0;
	n--;
}

void Application::print()
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			if(board[i][j]>=10)
				cout << board[i][j] << " ";
			else cout << board[i][j] << "  ";
		cout << endl;
	}
}
//application iterator
Application::Iterator::Iterator()
{
	Directions = 0;
};

Application::Iterator::Iterator(Position currP)
{
	curr = currP;
	Directions = 0;
}

Position Application::Iterator::getNextPossible(Application& a)
{
	Directions += 1; 
	int r = curr.getRow();
	int c = curr.getColumn();
	int x, y;

	n++;
	switch (Directions)
	{
	case 1:
		x = r - 2; y = c + 1;
		break;
	case 2:
		x = r - 1; y = c + 2;
		break;
	case 3:
		x = r + 1; y = c + 2;
		break;
	case 4:
		x = r + 2; y = c + 1;
		break;
	case 5:
		x = r + 2; y = c - 1;
		break;
	case 6:
		x = r + 1; y = c - 2;
		break;
	case 7:
		x = r - 1; y = c - 2;
		break;
	case 8:
		x = r - 2; y = c - 1; 
	    break;
	}
	if(!a.isValid(Position(x,y)))
		n--;

	return Position(x,y);
}

bool Application::Iterator::tryAllNextPossible()
{
	return (Directions==8);
}