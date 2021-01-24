#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include <windows.h>

void InitBoard(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		//打印数据 " %c | %c | %c " 
		for (j = 0; j < col; j++)
		{
			printf(" %c ",board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//打印分割行 "---|---|---"
		if (i < row - 1)
		{
			for (j = 0; j < col ; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
		
	}
}
void PlayerMove(char board[ROW][COL], int row, int col)
{
	
	int x, y;
	printf("轮到你了\n");
	while (1)
	{
		printf("请输入坐标(无括号，英文逗号隔开)>:");
		scanf("%d,%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= 3)
		{
			if (board[x-1][y-1] != ' ')
			{
				printf("此位置已有棋子，请重新选择落子位置");
			}
			else
			{
				board[x - 1][y - 1] = '#';
				break;
			}
		}
		else
		{
			printf("输入错误，请重新输入!\n");
			Sleep(2000);
		}
	}
	system("cls");
}
void CompuuterMove(char board[ROW][COL], int row, int col)
{
	
	printf("轮到人工智障了\n");
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '*';
			break;
		}
	}
	system("cls");
}
int Isfull(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
				break;
			}
		}
	}
	return 1;
}
char CheckWin(char board[ROW][COL], int row, int col)
{
	int i;
	
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] != ' ')
		{
			return board[i][0];
		}
	}
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[2][i] == board[1][i] && board[2][i] != ' ')
		{
			return board[0][i];
		}
	}
	//对角线
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != ' ')
	{
		return board[1][1];
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[0][2] != ' ')
	{
		return board[1][1];
	}
	//平局
	if (Isfull(board, row, col) == 1)
	{
		return 'q';
	}
	//继续
	return 'c';
}