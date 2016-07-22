#pragma once
#include<iostream>
using namespace std;
#include"Test.h"
#include<assert.h>
#include<vector>

//����һ�ö�������һ����������ӡ����������·��Ϊ����������·�����Ӹ��ڵ㵽Ҷ�ӽڵ�Ϊ·��

void _FindPath(BTreeNode* root, int sum, vector<int>& path, int currentsum)
{
	currentsum += root->_val;
	path.push_back(root->_val);

	if (currentsum == sum&&root->left == NULL&&root->right == NULL)
	{
		cout << "find a path:";
		vector<int>::iterator it = path.begin();

		while (it != path.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;;
	}

	if (root->left != NULL)
	{
		_FindPath(root->left, sum, path, currentsum);
	}
	if (root->right != NULL)
	{
		_FindPath(root->right, sum, path, currentsum);
	}

	path.pop_back();
}

void  FindPath(BTreeNode* root, int sum)
{
	if (root == NULL)
		return;

	vector<int>	path;
	int currentsum = 0;

	_FindPath(root, sum, path, currentsum);
}

