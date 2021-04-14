#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int row[8], n=8;//take note of which colomn could be put a queen in every row
//and there are 8 positions
int a[9][9] = { 0 }; //initialize the chessboard
int t = 1;//NO.t solution 
void print()
{
	printf("No. %d\n", t++);
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
bool judge(int num)
{
	for (int i = 1; i < num; i++)
		if (row[num] == row[i] || abs(row[i] - row[num]) == num - i)
			//the former condition means two positions are in the same colomn
			//the latter one means they're in the same diagonal
			//(the absolute value of difference of row is the same with that of colomn )
			return 0;
	return 1;
}
 
void findQueens(int num)
{
	if (num >= 9){
		print();
	}
	
	//for colomn 1-8
	for (int i = 1; i <=8; i++)
	{
		row[num] = i;
		//judge if position of chessboard:row=num, colomn=i could put a queen
		if (a[num][i]!=1&&judge(num))
		{
		//if it's ok. we assign 1 to this position
			a[num][i] = 1;
			//find a queen in next row
			findQueens(num + 1);
			//if it returns which means the row num+1 has no valid queen then:
			a[num][i] = 0;
		}
		
	}
	
}
 
int main()
{
	findQueens(1);
	return 0;
}

