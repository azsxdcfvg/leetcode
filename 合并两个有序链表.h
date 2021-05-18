#pragma once
#include<iostream>

/*
leetcode 网址:https://leetcode-cn.com/problems/merge-two-sorted-lists/
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

# 两个链表的节点数目范围是 [0, 50]
# -100 <= Node.val <= 100
# l1 和 l2 均按 非递减顺序 排列

测试用例
ListNode* tail1 = new ListNode(3);
	ListNode* mid1 = new ListNode(2, tail1);
	ListNode* head1 = new ListNode(1, mid1);

	ListNode* tail2 = new ListNode(5);
	ListNode* mid2 = new ListNode(2, tail2);
	ListNode* head2 = new ListNode(2, mid2);

	output(head1);
	output(head2);
	output(mergeTwoLists(head1, head2));

++++++++++++++++++++++++++++++++++++++
1.链表合并可以分解为更小的子问题,可以采用递归求解.
++++++++++++++++++++++++++++++++++++++
*/
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode* l1current = l1;
	ListNode* l2current = l2;
	ListNode* false_head = new ListNode(-1);
	ListNode* current = false_head;

	while (l1current != nullptr && l2current != nullptr) {
		if (l1current->val <= l2current->val) {
			current->next = l1current;
			l1current = l1current->next;
		}
		else {
			current->next = l2current;
			l2current = l2current->next;
		}
		current = current->next;
	}
	if (l1current == nullptr && l2current == nullptr) {
		;
	}
	else if (l1current == nullptr) {
		current->next = l2current;
	}
	else if(l2current == nullptr){
		current->next = l1current;
	}

	return false_head->next;
}

void output(ListNode* head) {
	int count = 0;
	if (head == nullptr) {
		std::cout << "nullptr" << std::endl;
	}
	while (head != nullptr) {
		count++;
		std::cout << count << ". " << head->val << " " << head << std::endl;
		head = head->next;
	}
}