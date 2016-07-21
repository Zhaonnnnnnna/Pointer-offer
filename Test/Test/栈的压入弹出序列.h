#pragma once
#include<iostream>
using namespace std;
#include"Test.h"
#include<stack>
#include<assert.h>

bool IsPopOrder(const int* Push, const int* Pop, int len)
{
	if (len <= 0)
		return true;
	const int* popcur = Pop;
	const int* pushcur = Push;

	stack<int> s;

	while (popcur - Pop < len)
	{
		while (s.empty() || s.top() != *popcur)
		{
			if (pushcur - Push == len)
				return false;

			s.push(*pushcur);
			pushcur++;
		}

		s.pop();
		popcur++;
	}

	if (s.empty())
		return true;
	
}
