#pragma once
#include<iostream>
using namespace std;
#include"Test.h"
#include<assert.h>

struct ComplexListNode {
	int val;
	struct ComplexListNode *next;
	struct ComplexListNode *random;

	ComplexListNode(int x)
		:val(x)
		, next(NULL)
		, random(NULL)
	{}

};


void CInsert(ComplexListNode*& head, int key)
{
	if (head == NULL)
	{
		head = new ComplexListNode(key);
		return;
	}


	ComplexListNode* cur = head;
	while (cur->next)
	{
		cur = cur->next;
	}
	cur->next = new ComplexListNode(key);
	return;

}

ComplexListNode* CFind(ComplexListNode* head, int x)
{
	if (head == NULL)
		return NULL;

	ComplexListNode* cur = head;
	while (cur)
	{
		if (cur->val == x)
			return cur;
		cur = cur->next;
	}

	return NULL;
}

//复杂链表的复制
//复制节点
void CloneNode(ComplexListNode* head)
{
	ComplexListNode* cur = head;
	while (cur)
	{
		ComplexListNode* newNode = new ComplexListNode(cur->val);
		newNode->next = cur->next;
		cur->next = newNode;
		cur = cur->next->next;
	}
}

//复制random指针
void CloneRandomPointer(ComplexListNode* head)
{
	ComplexListNode* cur = head;
	while (cur)
	{
		ComplexListNode* cloneNode = cur->next;
		if (cur->random != NULL)
		{
			cloneNode->random = cur->random->next;
		}
		cur = cur->next->next;
	}
}

//拆分链表
ComplexListNode* SplitList(ComplexListNode* head)
{
	ComplexListNode* CloneHead = head->next;
	ComplexListNode* CloneNode = head->next;
	ComplexListNode* cur = head;

	while (cur)
	{
		cur->next = CloneNode->next;
		if (cur->next != NULL)
		{
			CloneNode->next = cur->next->next;
		}
		cur = cur->next;
		CloneNode = CloneNode->next;
	}

	return CloneHead;

}

ComplexListNode* Clone(ComplexListNode* head)
{
	CloneNode(head);
	CloneRandomPointer(head);
	ComplexListNode* CloneHead = SplitList(head);
	
	return CloneHead;
}



void test()
{
	ComplexListNode* head = NULL;
	CInsert(head, 1);
	CInsert(head, 2);
	CInsert(head, 3);
	CInsert(head, 4);
	CInsert(head, 5);

	ComplexListNode* ret1 = CFind(head, 1);
	ComplexListNode* ret2 = CFind(head, 2);
	ComplexListNode* ret3 = CFind(head, 3);
	ComplexListNode* ret4 = CFind(head, 4);
	ComplexListNode* ret5 = CFind(head, 5);

	ret1->random = ret3;
	ret2->random = ret5;
	ret3->random = ret4;
	ret5->random = ret1;

	ComplexListNode* CloneHead = Clone(head);

}


