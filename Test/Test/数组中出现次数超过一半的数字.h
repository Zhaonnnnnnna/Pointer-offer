#pragma once
#include<iostream>
using namespace std;
#include"Test.h"
#include<assert.h>

bool g_validArray = false;

bool CheckInvalidArray(int* num, int len)
{
	if (num == NULL || len <= 0)
		return g_validArray;

	else
	{
		g_validArray = true;
		return g_validArray;
	}
}

int FastSort(int* num, int len, int start, int end)
{
	int left = start;
	int right = end - 1;
	int key = num[end];

	while (left < right)
	{
		while (left < right && num[left] <= key)
		{
			left++;
		}

		while (left < right && num[right] >= key)
		{
			right--;
		}

		if (left < right)
		{
			swap(num[left], num[right]);
			left++;
			right--;
		}
	}

	if (num[left]>key)
	{
		swap(num[left], num[end]);
	}
	return left;

}

bool CheckMoreThanHalf(int* num, int len, int number)
{
	int times = 0;
	for (int i = 0; i < len; i++)
	{
		if (num[i] == number)
			times++;
	}

	bool IsMoreThanHalf = true;

	if (times * 2 <= len)
	{
		IsMoreThanHalf = false;
		g_validArray = true;
	}

	return  IsMoreThanHalf;
}

int MoreThanHalfNum(int* num, int len)
{
	if (!CheckInvalidArray(num, len))
		return 0;

	int mid = len >> 1;
	int start = 0;
	int end = len - 1;
	int index = FastSort(num, len, start, end);

	while (index != mid)
	{
		if (index > mid)
		{
			index = FastSort(num, len, start, index - 1);
		}
		else
		{
			index = FastSort(num, len, index + 1, end);
		}
	}

	int result = num[index];

	if (!CheckMoreThanHalf(num, len, result))
		return -1;

	return result;
}

int MoreThanHalfNum1(int* num, int len)
{
	if (!CheckInvalidArray(num, len))
		return 0;

	int result = num[0];
	int times = 1;
	for (int i = 1; i < len; i++)
	{
		if (times == 0)
		{
			result = num[i];
			times = 1;
		}
		if (result != num[i])
		{
			times -= 1;
		}
		if (result == num[i])
		{
			times++;
		}
	}


	return result;
}




void test11()
{
	int num[] = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	int ret = MoreThanHalfNum1(num, 9);
	//cout << ret << endl;
}