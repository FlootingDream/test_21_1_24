#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "game.h"
void menu()
{
	printf("*******************************************\n");
	printf("********    1.play      0.exit     ********\n");
	printf("*******************************************\n");
}
void game()
{
	char board[ROW][COL];
	//初始化棋盘内容
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board,ROW,COL);
	char ret;
	while(1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret=CheckWin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
		//电脑下棋
		CompuuterMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret=CheckWin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
	}
	if (ret == '#')
	{
		printf("你赢了!\n");
	}
	else if (ret == '*')
	{
		printf("你输了!\n");
	}
	else if (ret == 'q')
	{
		printf("平局!\n");
	}
}
int main(int argc, char *argv[]) 
{
	srand((unsigned int)time(NULL));
	int input;
	do 
	{
		menu();
		printf("请选择>:\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:game();
			break;
		case 0:printf("退出成功\n");
			break;
		default:printf("输入错误，重新选择！\n");
			break;
		}
	} while (input);

	


	return 0;
}
