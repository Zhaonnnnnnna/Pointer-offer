#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<stack>

struct ListNode {
	int val;
	struct ListNode *next;

	ListNode(int x)
		:val(x)
		, next(NULL)
	{}

};

//ÄæÐò´òÓ¡Á´±í
vector<int> printListFromTailToHead(struct ListNode* head) {

	if (head == NULL)
		return vector<int>(0);

	ListNode* newHead = head;
	ListNode* prev = NULL;
	ListNode* cur = head;

	while (cur)
	{
		newHead = cur;
		cur = cur->next;

		newHead->next = prev;

		prev = newHead;
	}

	vector<int> tmp;
	cur = newHead;
	while (cur != NULL)
	{
		tmp.push_back(cur->val);
		cur = cur->next;
	}

	return tmp;
}


void Insert(ListNode*& head, int key)
{
	if (head == NULL)
	{
		head = new ListNode(key);
		return;
	}


	ListNode* cur = head;
	while (cur->next)
	{
		cur = cur->next;
	}
	cur->next = new ListNode(key);
	return;

}