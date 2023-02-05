#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)


class GameBoard
{
	int** arr;

private:

	int boardSize;

	int MoveInRow(int rowIndex, int indexInRow, int playerNum)
	{
		int res = 0;
		if (arr[rowIndex][indexInRow] == 0)
		{
			arr[rowIndex][indexInRow] = playerNum;
			res = 1;
		}
		return res;
	}

	int RowChecker(int playerNum)
	{
		int res = 1;

		for (size_t i = 0; i < boardSize; i++)
		{
			bool isRawOfSameNum = true;
			for (size_t j = 0; j < boardSize; j++)
			{
				if (arr[i][j] != playerNum)
				{
					isRawOfSameNum = false;
				}
			}
			if (isRawOfSameNum == true)
			{
				res = 1;
			}
		}

		return res;
	}

	int ColumnsChecker(int playerNum)
	{
		int res = 1;

		for (size_t i = 0; i < boardSize; i++)
		{
			bool isRawOfSameNum = true;
			for (size_t j = 0; j < boardSize; j++)
			{
				if (arr[j][i] != playerNum)
				{
					isRawOfSameNum = false;
				}
			}
			if (isRawOfSameNum == true)
			{
				res = 1;
			}
		}

		return res;
	}




public:
	GameBoard()
	{
		arr = (int**)calloc(3, sizeof(int*));

		for (size_t i = 0; i < 3; i++)
		{
			arr[i] = (int*)calloc(3, sizeof(int));
		}

	}

	int CheckForWin()
	{
		int res = 0;;

		if (ColumnsChecker(1) || RowChecker(1))
		{
			res = 1;
		}

		bool isPlayerTwoWon = false;
		if (ColumnsChecker(2) || RowChecker(2))
		{
			res = 2;
		}

		return res;
	}


	int Move(int moveLocation, int playerNum)
	{
		int res = 0; // 0 is fail

		if (moveLocation >= 1 && moveLocation <= 9)
		{
			int rowIndex = -1;

			if (moveLocation >= 1 && moveLocation <= 3)
			{
				rowIndex = 0;
			}

			else if (moveLocation >= 4 && moveLocation <= 6)
			{
				rowIndex = 1;
			}

			else if (moveLocation >= 7 && moveLocation <= 9)
			{
				rowIndex = 2;
			}

			int indexInRow = (moveLocation - rowIndex * boardSize) - 1;
			res = MoveInRow(rowIndex, indexInRow, playerNum);
		}

		return res;
	}

	void PrintBoard()
	{
		for (int i = 0; i < boardSize; i++)
		{
			for (int j = 0; j < boardSize; j++)
			{
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
	}
};


class TicTacTou : GameBoard
{
private:


public:
	void Play()
	{
		int gameEnd = 0;

		while (gameEnd == 0)
		{
			for (size_t playerTurn = 1; playerTurn <= 2; playerTurn++)
			{
				int legalMove = 0;
				while (legalMove == 0)
				{
					printf("player %d turn, enter index: ", playerTurn);

					int moveLocation;
					scanf("%d", &moveLocation);
					legalMove = Move(moveLocation, playerTurn);
				}
				printf("\n");
				PrintBoard();
				printf("\n\n");

				int winner = CheckForWin();
				if (winner)
				{
					printf("\n\n Congrat player %d you won!!! \n\n ", winner);
				}

			}
		}
	}
};



int main()
{
	int* arr = new int[3];

	int a = 123;

	int len = 0;

	while (a > 0)
	{
		a = a / 10;
		len++;
	}

	printf("%d", len);

}