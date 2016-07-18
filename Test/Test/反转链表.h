#pragma once
#include<iostream>
using namespace std;
#include"Test.h"


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