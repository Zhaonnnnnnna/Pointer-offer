#pragma once
#include<iostream>
using namespace std;
#include"Test.h"


void MirrorBTree(BTreeNode* root)
{
	if (root == NULL)
		return;

	if (root->left == NULL && root->right == NULL)
		return;

	swap(root->left, root->right);

	if (root->left)
		MirrorBTree(root->left);

	if (root->right)
		MirrorBTree(root->right);
}