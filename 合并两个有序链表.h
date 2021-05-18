#pragma once
#include<iostream>

/*
leetcode ��ַ:https://leetcode-cn.com/problems/merge-two-sorted-lists/
��������������ϲ�Ϊһ���µ� ���� �������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�

# ��������Ľڵ���Ŀ��Χ�� [0, 50]
# -100 <= Node.val <= 100
# l1 �� l2 ���� �ǵݼ�˳�� ����

��������
ListNode *tail = new ListNode(3);
ListNode *mid = new ListNode(2, tail);
ListNode *head = new ListNode(1, mid);

++++++++++++++++++++++++++++++++++++++
1.���ڵ������������,����ջ;
2.�Ҳ������Ž�ʱ,�ռ任ʱ��
3.����ɾ������ʹ��α�ײ���ʽ
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