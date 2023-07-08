#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3

void game();
//构建二维数组的函数
void isboard(char board[ROW][COL], int row, int col);
//构建一个棋盘

void displayboard(char board[ROW][COL], int row, int col);
//玩家操作
void playmove(char board[ROW][COL], int row, int col);
//电脑操作
void computmove(char board[ROW][COL], int row, int col);
//判断输赢
char is_win(char board[ROW][COL], int row, int col);
