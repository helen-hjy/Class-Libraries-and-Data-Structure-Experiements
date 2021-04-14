#include<iostream>
using namespace std;

class eightqueen {
private:
	int chess[8][8];//create a 8X8 chess table
	const int size = 8; //the size should be a constant
public: 
	eightqueen() {    //create a default chess table by construtor
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				chess[i][j] = 0;
	};

		void printchess() {   //a default printing method
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
					cout << chess[i][j] << " ";
				cout << endl;
			}
		};
		void goBack(int r, int c) { //if the position is not valid, return it to default 0 value
			chess[r][c] = 0;
		};

		bool findPosition(int r, int c);//the recurion method to find queens
		bool isValid(int r, int c);//test if it's valid
};
bool eightqueen::isValid(int r, int c)
{
	if (r ==size || r < 0 || c ==size || c < 0) 
		//a default restriction for every chess: cannot be put out of table
		return false;
	for (int i = 0; i< size; i++) 
	{
		if (chess[i][c]==1)
			return false;
	}// I put every queen line by line. just check if the colomn is valid
	
	//below two loops are checks for diagonals
	for (int n = 0; r - n >= 0&&c-n>=0; n++) 
		if (chess[r - n][c - n] == 1)
			return false;   //this is for top left diagonal

	for (int n = 0; r - n >= 0 && c + n < size; n++)
		if (chess[r - n][c + n] == 1)
			return false; //this is for top right diagonal

	return true;//occasions except above situations are all true
}
bool eightqueen::findPosition(int r,int c){ 
	if (isValid(r, c)) //firstly check the postion[r][c] in chess table
	{
		chess[r][c] = 1;//if it's valid. Put an 1 on it
		if(r+1< size) //we need to backtrack the next line so check if it's the end
		{
			for (int i = 0; i < size; i++) 
		    {
				if (findPosition(r+1, i))//this loop is to check every position of the next line
				{
					chess[r+1][i] = 1; //if the next line has a valid position, then we put a queen(i.e. 1)
					return true;		
				}
				//otherwise we check if this line has no valid position
				else if (i == size - 1) { 
					goBack(r,c); 
					return false;
				}	//if there's no valid postion, we should go back and return false
			}
		}
	}
}//for two outside "if"s, they return true in default
int main(){

	eightqueen eigque;
	cout<<"Eight queens should be set as:"<<endl;
	
	if (eigque.findPosition(0, 0))
				eigque.printchess();
	else cout << "NO SOLUTION" << endl; //print if there's a valid position for 8 queens
}
