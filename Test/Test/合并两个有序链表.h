#pragma once
#include<iostream>
using namespace std;
#include"Test.h"

//合并两个有序链表
ListNode* MergeList(ListNode* head1, ListNode* head2)
{
	if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;

	ListNode* newHead = NULL;
	if (head1->val < head2->val)
	{
		newHead = head1;
		newHead->next = MergeList(head1->next, head2);
	}
	else
	{
		newHead = head2;
		newHead->next = MergeList(head1, head2->next);
	}

	return newHead;
}
