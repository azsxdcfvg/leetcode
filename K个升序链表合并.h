#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
leetcode 网址:https://leetcode-cn.com/problems/merge-k-sorted-lists/
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

# k == lists.length
# 0 <= k <= 10^4
# 0 <= lists[i].length <= 500
# -10^4 <= lists[i][j] <= 10^4
# lists[i] 按 升序 排列
# lists[i].length 的总和不超过 10^4



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
1.涉及顺序可以用优先队列(堆)
2.掌握C++堆库的使用方式,在algorithm库中,见 http://c.biancheng.net/view/481.html
3.注意对堆的生成,弹出,插入,都要指明自己设置的比较函数.<为最小堆,>为最大堆
++++++++++++++++++++++++++++++++++++++
思路1.
两两合并,总共时间复杂度级别还是O(n),但是有重复遍历;170ms左右,
思路2.
两两合并->kk合并,每次找到最小的数O(n),维护一个列表记录当前指针.
复杂度相同,但是减少了重复读的次数.
官网:使用优先队列
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