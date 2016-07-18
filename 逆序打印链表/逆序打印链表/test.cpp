#include"test.h"

void test()
{
	struct ListNode* head = NULL;
	Insert(head,67);
	Insert(head,0);
	Insert(head,24);
	Insert(head,58);

	vector<int>  ret = printListFromTailToHead(head);
}


int main()
{
	test();
	getchar();
	return 0;

}

