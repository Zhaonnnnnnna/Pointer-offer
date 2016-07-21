#pragma once
#include<iostream>
using namespace std;
#include"Test.h"
#include<stack>
#include<assert.h>


class Stack
{
public:
	void Push(int x)
	{
		s1.push(x);
		
		if (s2.empty())
			s2.push(x);
		else
		{
			if (x > s2.top())
				s2.push(s2.top());
			else
				s2.push(x);
		}
	}

	void Pop()
	{
		assert(s1.size() > 0 && s2.size() > 0);

		s1.pop();
		s2.pop();
	}

	int Min()
	{
		assert(s1.size() > 0 && s2.size() > 0);

		return s2.top();
	}

private:
	stack<int> s1;
	stack<int> s2;	//¸¨ÖúÕ»

};