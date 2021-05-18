#pragma once
#include<iostream>

/*
leetcode 网址:https://leetcode-cn.com/problems/merge-two-sorted-lists/
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

# 两个链表的节点数目范围是 [0, 50]
# -100 <= Node.val <= 100
# l1 和 l2 均按 非递减顺序 排列

测试用例
ListNode *tail = new ListNode(3);
ListNode *mid = new ListNode(2, tail);
ListNode *head = new ListNode(1, mid);

++++++++++++++++++++++++++++++++++++++
1.对于倒数这样的情况,考虑栈;
2.找不到最优解时,空间换时间
3.链表删除操作使用伪首部方式
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
		current = (l1current->val <= l2current->val) ? l1current : l2current;

	}
}