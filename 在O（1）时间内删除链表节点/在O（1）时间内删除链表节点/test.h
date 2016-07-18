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

//��O��1��ʱ����ɾ������ڵ�
void DeleteNode(ListNode* head, ListNode* pos)
{
	if (head == NULL || pos == NULL)
		return;

	ListNode* cur = head;
	//����ֻ��һ���ڵ�
	if (cur == pos)
	{
		delete head;
		head = NULL;
		pos = NULL;
	}
	//ɾ���Ĳ���β�ڵ�
	else if (pos->next != NULL)
	{
		ListNode* next = pos->next;
		pos->val = next->val;
		pos->next = next->next;

		delete next;
		next = NULL;
	}
	//ɾ��β�ڵ�
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
