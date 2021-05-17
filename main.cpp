#include"删除链表的倒数第 N 个结点.h"
using namespace std;

int main() {
	ListNode* tail = new ListNode(3);
	ListNode* mid = new ListNode(2, tail);
	ListNode* head = new ListNode(1, mid);
	output(head);
	//output(removeNthFromEnd_my_brute(head, 3));
	output(removeNthFromEnd_standard(head, 3));
}