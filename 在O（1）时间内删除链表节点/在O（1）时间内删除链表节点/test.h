#pragma once
#include<iostream>
using namespace std;

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

ListNode* Find(ListNode* head, int x)
{
	if (head == NULL)
		return NULL;

	ListNode* cur = head;
	while (cur)
	{
		if (cur->val == x)
			return cur;
		cur = cur->next;
	}

	return NULL;
}

//在O（1）时间内删除链表节点
void DeleteNode(ListNode* head, ListNode* pos)
{
	if (head == NULL || pos == NULL)
		return;

	ListNode* cur = head;
	//链表只有一个节点
	if (cur == pos)
	{
		delete head;
		head = NULL;
		pos = NULL;
	}
	//删除的不是尾节点
	else if (pos->next != NULL)
	{
		ListNode* next = pos->next;
		pos->val = next->val;
		pos->next = next->next;

		delete next;
		next = NULL;
	}
	//删除尾节点
	else
	{
		while (cur->next->next)
		{
			cur = cur->next;
		}
		cur->next = NULL;
		delete pos;
		pos = NULL;
	}
}
