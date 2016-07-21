#pragma once
#include<iostream>
using namespace std;
#include"Test.h"

bool HasSubTree(BTreeNode* root1, BTreeNode* root2)
{
	if (root2 == NULL)
		return true;
	if (root1 == NULL)
		return false;

	if (root1->_val != root2->_val)
		return false;

	return HasSubTree(root1->left, root2->left) && HasSubTree(root1->right, root2->right);
}

bool IsSubTree(BTreeNode* root1, BTreeNode* root2)
{
	bool result = false;

	if (root1 != NULL&&root2 != NULL)
	{
		if (root1->_val == root2->_val)
			result = HasSubTree(root1, root2);

		if (!result)
		{
			result = IsSubTree(root1->left, root2);
		}
		if (!result)
		{
			result = IsSubTree(root1->right, root2);
		}
	}

	return result;
}

