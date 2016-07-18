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

//·´×ªÁ´±í
ListNode* ReverseList(ListNode* head)
{
	if (head == NULL)
		return NULL;
	if (head->next == NULL)
		return head;

	ListNode* prev = NULL;
	ListNode* cur = head;
	ListNode* newHead = NULL;
	while (cur)
	{
		newHead = cur;
		cur = cur->next;
		newHead->next = prev;
		prev = newHead;
	}

	return newHead;
}