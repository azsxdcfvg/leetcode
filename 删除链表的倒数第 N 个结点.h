#pragma once
#include<iostream>
/*
leetcode ��ַ:https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
����һ������ɾ������ĵ����� n ����㣬���ҷ��������ͷ��㡣
���ף����ܳ���ʹ��һ��ɨ��ʵ����

# �����н�����ĿΪ sz
# 1 <= sz <= 30
# 0 <= Node.val <= 100
# 1 <= n <= sz

��������
ListNode* tail = new ListNode(3);
ListNode* mid = new ListNode(2, tail);
ListNode* head = new ListNode(1, mid);
output(head);
//output(removeNthFromEnd_my_brute(head, 3));
output(removeNthFromEnd_standard(head, 3));

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

ListNode* removeNthFromEnd_my_brute(ListNode* head, int n) {
	/*
	��һ����㳤��,�ڶ���ɾ��
	*/
	int len_of_list = 0; //������
	ListNode* current = head;
	ListNode* false_head = new ListNode(-1, head);
	while (current != nullptr) {
		len_of_list++;
		current = current->next;
	}
	std::cout << "������:" << len_of_list << std::endl;
	std::cout << "+++" << std::endl;
	int index = len_of_list - n ;//������Ŀ,���㿪ʼ
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
	//��֪���ܳ��Ȳ�����֪����Ӧλ��,���Ǳ������м�¼.ʹ��ָ������,����<=30;�������Ƶ�����ջ�ṹ
	//�ռ临�Ӷ�N;
	ListNode* current = head;
	ListNode* nodes[30] = { nullptr };
	int count = 0;
	while (current != nullptr) {
		nodes[count] = current;
		current = current->next;
		count++;
	}

	//һ��������,ͬʱ,����һ������;ɾ��������count - n;���㿪ʼ
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
����ָ��
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