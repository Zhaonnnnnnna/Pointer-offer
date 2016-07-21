#pragma once
#include<iostream>
using namespace std;
#include"Test.h"

void PrintNum(int num)
{
	cout << num << " ";
}

void PrintMatrixInCircle(int num[][4], int row, int col, int start)
{
	int endy = col - 1 - start;
	int endx = row - 1 - start;

	//从左到右打印一行
	for (int i = start; i <= endy; i++)
	{
		int number = num[start][i];
		PrintNum(number);
	}

	//从上到下打印一行
	if (start < endx)
	{
		for (int i = start + 1; i <= endx; i++)
		{
			int number = num[i][endx];
			PrintNum(number);
		}
	}

	//从右到左打印一行
	if (start < endx && start < endy)
	{
		for (int i = endy - 1; i >= start; i--)
		{
			int number = num[endx][i];
			PrintNum(number);
		}
	}

	//从下到上打印一行
	if (start < endx - 1 && start < endy)
	{
		for (int i = endx - 1; i >= start + 1; i--)
		{
			int number = num[i][start];
			PrintNum(number);
		}
	}

}

void PrintMatrixClockwise(int num[][4], int row, int col)
{
	if (num == NULL || col == 0 || row == 0)
		return;

	int start = 0;
	while (col > start * 2 && row > start * 2)
	{
		PrintMatrixInCircle(num, row, col, start);
		start++;
	}


}
