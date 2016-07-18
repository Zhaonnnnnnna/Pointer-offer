#include"test.h"

int main()
{
	ListNode* head2 = NULL;
	Insert(head2, 2);
	Insert(head2, 4);
	Insert(head2, 6);
	Insert(head2, 8);



	ListNode* newHead = ReverseList(head2);

	return 0;
}
