#pragma once
#include<iostream>
using namespace std;   
#include<stack>
#include"Test.h"


//用两个栈实现队列
class Queue
{
public:
	Queue()
	{}

	~Queue()
	{}

public:
	void Push_back(int k)
	{
		s1.push(k);
	}


	void Pop_front()
	{
		if (s1.size() == 0 && s2.size() == 0)
			return;
		if (s2.size() == 0)
		{
			while (!s1.empty())
			{
				int k = s1.top();
				s2.push(k);
				s1.pop();
			}
		}

		s2.pop();
	}
private:
	stack<int> s1;
	stack<int> s2;
};