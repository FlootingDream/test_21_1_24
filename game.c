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
	//��ʼ����������
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board,ROW,COL);
	char ret;
	while(1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret=CheckWin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
		//��������
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
		printf("��Ӯ��!\n");
	}
	else if (ret == '*')
	{
		printf("������!\n");
	}
	else if (ret == 'q')
	{
		printf("ƽ��!\n");
	}
}
int main(int argc, char *argv[]) 
{
	srand((unsigned int)time(NULL));
	int input;
	do 
	{
		menu();
		printf("��ѡ��>:\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:game();
			break;
		case 0:printf("�˳��ɹ�\n");
			break;
		default:printf("�����������ѡ��\n");
			break;
		}
	} while (input);

	


	return 0;
}
