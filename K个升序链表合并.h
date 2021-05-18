#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
leetcode ��ַ:https://leetcode-cn.com/problems/merge-k-sorted-lists/
��������������ϲ�Ϊһ���µ� ���� �������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�

# k == lists.length
# 0 <= k <= 10^4
# 0 <= lists[i].length <= 500
# -10^4 <= lists[i][j] <= 10^4
# lists[i] �� ���� ����
# lists[i].length ���ܺͲ����� 10^4



��������
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
1.�漰˳����������ȶ���(��)
2.����C++�ѿ��ʹ�÷�ʽ,��algorithm����,�� http://c.biancheng.net/view/481.html
3.ע��Զѵ�����,����,����,��Ҫָ���Լ����õıȽϺ���.<Ϊ��С��,>Ϊ����
++++++++++++++++++++++++++++++++++++++
˼·1.
�����ϲ�,�ܹ�ʱ�临�Ӷȼ�����O(n),�������ظ�����;170ms����,
˼·2.
�����ϲ�->kk�ϲ�,ÿ���ҵ���С����O(n),ά��һ���б��¼��ǰָ��.
���Ӷ���ͬ,���Ǽ������ظ����Ĵ���.
����:ʹ�����ȶ���
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
	else if (l2current == nullptr) {
		current->next = l1current;
	}

	return false_head->next;
}


ListNode* mergeKLists_two_two(vector<ListNode*>& lists) {
	if (lists.size() == 0) {
		return nullptr;
	}
	ListNode* head = lists[0];
	for (int i = 1; i < lists.size(); i++) {
		head = mergeTwoLists(head, lists[i]);
	}

	return head;
}


bool cmp(ListNode* first, ListNode* second) {
	return first->val > second->val;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
	vector<ListNode*> list_heap;
	
	for (int i = 0; i < lists.size(); i++) {
		ListNode* current = lists[i];
		while (current != nullptr) {
			list_heap.push_back(current);
			current = current->next;
		}
	}
	make_heap(list_heap.begin(), list_heap.end(), cmp);

	ListNode* false_head = new ListNode(-1, nullptr);
	while (!list_heap.empty()) {
		pop_heap(list_heap.begin(), list_heap.end(), cmp);
		(*(list_heap.end() - 1))->next = false_head->next;
		false_head->next = *(list_heap.end() - 1);
		list_heap.pop_back();
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