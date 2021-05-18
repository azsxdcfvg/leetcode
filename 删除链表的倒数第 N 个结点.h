#pragma once
#include<iostream>
/*
leetcode 网址:https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
进阶：你能尝试使用一趟扫描实现吗？

# 链表中结点的数目为 sz
# 1 <= sz <= 30
# 0 <= Node.val <= 100
# 1 <= n <= sz

测试用例
ListNode* tail = new ListNode(3);
ListNode* mid = new ListNode(2, tail);
ListNode* head = new ListNode(1, mid);
output(head);
//output(removeNthFromEnd_my_brute(head, 3));
output(removeNthFromEnd_standard(head, 3));

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

ListNode* removeNthFromEnd_my_brute(ListNode* head, int n) {
	/*
	第一遍计算长度,第二遍删除
	*/
	int len_of_list = 0; //链表长度
	ListNode* current = head;
	ListNode* false_head = new ListNode(-1, head);
	while (current != nullptr) {
		len_of_list++;
		current = current->next;
	}
	std::cout << "总数量:" << len_of_list << std::endl;
	std::cout << "+++" << std::endl;
	int index = len_of_list - n ;//整数数目,从零开始
	current = head;
	ListNode* pre = false_head;
	while (index != 0) {
		pre = current;
		current = current->next;
		index--;
	}
	std::cout << "+++" << std::endl;
	pre->next = current->next;
	delete current;

	return false_head->next;
}


ListNode* removeNthFromEnd_my_standard(ListNode* head, int n) {
	//不知道总长度不可能知道对应位置,考虑遍历进行记录.使用指针数组,利用<=30;官网类似的用了栈结构
	//空间复杂度N;
	ListNode* current = head;
	ListNode* nodes[30] = { nullptr };
	int count = 0;
	while (current != nullptr) {
		nodes[count] = current;
		current = current->next;
		count++;
	}

	//一遍获得总数,同时,有了一个数组;删除整数第count - n;从零开始
	int delete_loc = count - n;
	if (count - n == 0) {
		delete nodes[0];
		return nodes[1];
	}
	else {
		delete nodes[delete_loc];
		nodes[delete_loc - 1]->next = nodes[delete_loc + 1];
		return nodes[0];
	}
}

/*
快慢指针
*/

ListNode* removeNthFromEnd_standard(ListNode* head, int n) {
	ListNode* slow = head;
	ListNode* false_head = new ListNode(-1, head);
	ListNode* current = false_head;
	ListNode* fast = head;
	int count = n;
	while (count > 0) {
		fast = fast->next;
		count--;
	}
	while (fast != nullptr) {
		fast = fast->next;
		slow = slow->next;
		current = current->next;
	}

	current->next = slow->next;
	delete slow;
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