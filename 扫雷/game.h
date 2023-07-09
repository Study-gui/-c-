#pragma once
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define easy_saolei 10
void displayboard(char board [ROWS][COLS], int rows, int cols,char ret);

void is_board(char board[ROWS][COLS], int row, int col);

void set_mine(char board[ROWS][COLS], int row, int col);

void playboard(char mine[ROWS][COLS],char show[ROWS][COLS], int row,int col);
