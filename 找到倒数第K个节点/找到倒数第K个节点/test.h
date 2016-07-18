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


//找到倒数第K个节点
ListNode* FindKToTail(ListNode* head, int k)
{
	if (head == NULL || k <= 0)
		return NULL;

	ListNode* first = head;
	ListNode* second = head;
	while (k--)
	{
		first = first->next;
	}

	while (first)
	{
		first = first->next;
		second = second->next;
	}

	return second;
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