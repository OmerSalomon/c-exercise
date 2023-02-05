#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

const int numberOfRow_const = 5;
const int numberOfColumns_const = 5;

typedef struct 
{
	int ** board;
	int numberOfRows;
	int numberOfColumns;
}GameData;

typedef struct
{
	int rowIndex;
	int columnIndex;
}Cord;

void printBoard(GameData d)
{
	for (size_t i = 0; i < d.numberOfRows; i++)
	{
		int * row = d.board[i];
		for (size_t j = 0; j < d.numberOfColumns; j++)
		{
			printf("%d ", row[j]);
		}
		printf("\n");
	}
}



Cord findPos(GameData d, int pos)
{
	Cord c;
	int count = 0;
	for (size_t i = 1; i <= d.numberOfRows; i++)
	{
		for (size_t j = 1; j <= d.numberOfColumns; j++)
		{
			count += 1;
			if (count == pos)
			{
				c.rowIndex = i;
				c.columnIndex = j;
			}
		}
	}
	return c;
}



void makeMove(GameData d, int playerSign)
{
	Cord c;
	int pos = 1;
	bool isLegitMove = false;
	while (pos >= 1 && pos <= d.numberOfColumns * d.numberOfRows && !isLegitMove)
	{
		printf("Enter pos: ");
		scanf("%d", &pos);
		printf("\n");
		c = findPos(d, pos);
		if (d.board[c.rowIndex - 1][c.columnIndex - 1] == 0)
		{
			d.board[c.rowIndex - 1][c.columnIndex - 1] = playerSign;
			isLegitMove = true;
		}
		else
		{
			printf("Illegal move\n");
		}
	}
}


int checkColumns(GameData d)
{
	int winner = 0;
	for (size_t i = 0; i < d.numberOfColumns; i++)
	{
		int playerOnePoints = 0;
		int playerTwoPoints = 0;

		for (size_t j = 0; j < d.numberOfRows; j++)
		{
			if (d.board[j][i] == 1)
				playerOnePoints += 1;
			if (d.board[j][i] == 2)
				playerTwoPoints += 1;
		}

		if (playerOnePoints == d.numberOfColumns)
			winner = 1;
		if (playerTwoPoints == d.numberOfColumns)
			winner = 2;

	}
	

	return winner;
}


int checkRows(GameData d)
{
	int winner = 0;
	for (size_t i = 0; i < d.numberOfRows; i++)
	{
		int playerOnePoints = 0;
		int playerTwoPoints = 0;

		for (size_t j = 0; j < d.numberOfColumns; j++)
		{
			if (d.board[i][j] == 1)
				playerOnePoints += 1;
			if (d.board[i][j] == 2)
				playerTwoPoints += 1;
		}
		if (playerOnePoints == d.numberOfRows)
			winner = 1;
		if (playerTwoPoints == d.numberOfRows)
			winner = 2;

	}
	return winner;
}

int checkForWinner(GameData d)
{
	int res = 0;
	res = checkRows(d);
	if (res == 0)
	{
		res = checkColumns(d);
	}
	return res;
}

int main()
{

	int* board[numberOfRow_const];
	int row1[numberOfColumns_const], row2[numberOfColumns_const], row3[numberOfColumns_const] ,row4[numberOfColumns_const] ,row5[numberOfColumns_const];
	
	for (size_t i = 0; i < numberOfColumns_const; i++)
	{
		row1[i] = 0;
		row2[i] = 0;
		row3[i] = 0;
		row4[i] = 0;
		row5[i] = 0;
	}

	board[0] = row1;
	board[1] = row2;
	board[2] = row3;
	board[3] = row4;
	board[4] = row5;
	
	int numberOfRows, numberOfColumns;
	printf("Please enter number of rows: ");
	scanf("%d", &numberOfRows);
	printf("\nPlease enter numbwe of columns: ");
	scanf("%d", &numberOfColumns);

	GameData d;
	d.board = board;
	d.numberOfRows = numberOfRows;
	d.numberOfColumns = numberOfColumns;

	printf("\n");

	int pos;
	int winner = 0;

	int playerSign = 1;
	
	while (winner == 0)
	{
		printf("\n");
		makeMove(d,playerSign);
		winner = checkForWinner(d);
		printBoard(d);

		if (playerSign == 1)
			playerSign = 2;
		else
			playerSign = 1;
	}
	printf("\nplayer %d is the winner", winner);
	
	
	

}