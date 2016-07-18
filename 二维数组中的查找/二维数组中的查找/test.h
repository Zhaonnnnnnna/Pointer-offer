#pragma once
#include<iostream>
using namespace std;
#include<vector>

//Êý×éÕÒÊý
class Solution {
public:
	bool Find(vector<vector<int> > array, int target)
	{
		int row = array.size();
		int col = sizeof(array[0].size());
		int i = 0;
		int j = 0;
		for (i = 0; i<row;)
		{
			for (j = col - 1; j >= 0;)
			{
				if (i < row &&j >= 0 && array[i][j]<target)
					i++;
				else if (i < row &&j >= 0 && array[i][j]>target)
					j--;
				else
				{
					if (i < row&&j >= 0)
						return true;
					else
						return false;
				}

			}

		}
		return false;
	}
};

struct ListNode {
	int val;
	struct ListNode *next;

	ListNode(int x)
		:val(x)
		, next(NULL)
	{}

};