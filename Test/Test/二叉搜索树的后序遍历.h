#pragma once
#include<iostream>
using namespace std;
#include"Test.h"
#include<assert.h>

 //����һ���������飬�ж������ǲ��Ƕ����������ĺ�������Ľ��
bool ISPostOrderBST(int arr[], int len)
{
	if (arr == NULL || len <= 0)
		return false;

	int root = arr[len - 1];

	int i = 0;
	for (i = 0; i < len - 1; i++)
	{
		if (arr[i] > root)
			break;
	}

	int j = i;
	for (; j < len - 1; j++)
	{
		if (arr[j] < root)
			return false;
	}

	bool left = true;
	if (i>0)
		left = ISPostOrderBST(arr, i);
	bool right = true;
	if (i < len - 1)
		right = ISPostOrderBST(arr + i, len - i - 1);

	return (left && right);
}