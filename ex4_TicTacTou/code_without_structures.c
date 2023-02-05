#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

const int numberOfRow_const = 5;
const int numberOfColumns_const = 5;

typedef struct 
{
	int*** board;
	int numberOfRow;
	int numberOfColumns;
}GameData;


void printBoard(int ** arr ,int numberOfRows, int numberOfColunms)
{
	for (size_t i = 0; i < numberOfRows; i++)
	{
		int * row = arr[i];
		for (size_t j = 0; j < numberOfColunms; j++)
		{
			printf("%d ", row[j]);
		}
		printf("\n");
	}
}

void createBoard(int *** board, int numberOfRow, int numberOfColumns)
{
	for (size_t i = 0; i < numberOfRow; i++)
	{
		int row[5];

		for (size_t i = 0; i < numberOfColumns; i++)
		{
			row[i] = 0;
		}
		*board[i] = row;
	}
}


void findPos(int pos, int numberOfRows, int numberOfColumns, int * rowIndex, int* columnIndex)
{
	int count = 0;
	for (size_t i = 1; i <= numberOfRows; i++)
	{
		for (size_t j = 1; j <= numberOfColumns; j++)
		{
			count += 1;
			if (count == pos)
			{
				*rowIndex = i;
				*columnIndex = j;
			}
		}
	}
}



void makeMove(int ** board, int pos, int playerSign, int numberOfRows, int numberOfColumns)
{
	int rowIndex;
	int columnIndex;
	findPos(pos, numberOfRows, numberOfColumns, &rowIndex, &columnIndex);
	board[rowIndex - 1][columnIndex - 1] = playerSign;
}


int checkColumns(int** board, int numberOfRow, int numberOfColumns)
{
	int winner = 0;
	for (size_t i = 0; i < numberOfColumns; i++)
	{
		int playerOnePoints = 0;
		int playerTwoPoints = 0;

		for (size_t j = 0; j < numberOfRow; j++)
		{
			if (board[j][i] == 1)
				playerOnePoints += 1;
			if (board[j][i] = 2)
				playerTwoPoints += 1;
		}

		if (playerOnePoints = numberOfColumns)
			winner = 1;
		if (playerTwoPoints = numberOfColumns)
			winner = 2;
	}
	return winner;
}


int checkRows(int ** board, int numberOfRow, int numberOfColumns)
{
	int winner = 0;
	for (size_t i = 0; i < numberOfRow; i++)
	{
		int playerOnePoints = 0;
		int playerTwoPoints = 0;

		for (size_t j = 0; j < numberOfColumns; j++)
		{
			if (board[i][j] == 1)
				playerOnePoints += 1;
			if (board[i][j] == 2)
				playerTwoPoints += 1;
		}

		if (playerOnePoints = numberOfColumns)
			winner = 1;
		if (playerTwoPoints = numberOfColumns)
			winner = 2;
	}
	return winner;
}

int checkForWinner(int ** board, int numberOfRows, int numberOfColumns)
{
	int res = 0;
	res = checkRows(board, numberOfRows, numberOfColumns);
	if (res == 0)
	{
		res = checkColumns(board, numberOfRows, numberOfColumns);
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

	printf("\n");

	int pos;
	int winner = 0;

	while (winner == 0)
	{
		printf("player 1 turn:\n");
		scanf("%d", &pos);
		makeMove(board, pos, 1, numberOfRows, numberOfColumns);
		
		winner = checkForWinner(board, numberOfRows, numberOfColumns);
		printBoard(board, numberOfRows, numberOfColumns);

		printf("player 2 turn:\n");
		scanf("%d", &pos);
		makeMove(board, pos, 2, numberOfRows, numberOfColumns);
		printBoard(board, numberOfRows, numberOfColumns);

		winner = checkForWinner(board, numberOfRows, numberOfColumns);
	}
	printf("\nplayer %d is the winner", winner);

}