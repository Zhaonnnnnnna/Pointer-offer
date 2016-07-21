#pragma once
#include<iostream>
using namespace std;
#include"Test.h"
#include<queue>
#include<assert.h>


void _LevelOrder(BTreeNode* root)
{
	if (root == NULL)
		return;

	queue<BTreeNode*> q;
	q.push(root);

	while (!q.empty())
	{
		BTreeNode* tmp = q.front();
		cout << tmp->_val << " ";
		q.pop();

		if (tmp->left != NULL)
			q.push(tmp->left);

		if (tmp->right != NULL)
			q.push(tmp->right);
	}

}

void LevelOrder(BTreeNode* root)
{
	_LevelOrder(root);
}