#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3

void game();
//������ά����ĺ���
void isboard(char board[ROW][COL], int row, int col);
//����һ������

void displayboard(char board[ROW][COL], int row, int col);
//��Ҳ���
void playmove(char board[ROW][COL], int row, int col);
//���Բ���
void computmove(char board[ROW][COL], int row, int col);
//�ж���Ӯ
char is_win(char board[ROW][COL], int row, int col);
