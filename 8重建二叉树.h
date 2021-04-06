#pragma once
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode {
	int val = 0;
	TreeNode* left = NULL;
	TreeNode* right = NULL;
};

//测试正确性
void BFS(TreeNode* root) {
	queue<TreeNode*> trees;
	trees.push(root);
	while (!trees.empty()) {
		TreeNode* tree = trees.front();
		cout << tree->val << endl;
		if (tree->left != NULL) {
			trees.push(tree->left);
		}
		if (tree->right != NULL) {
			trees.push(tree->right);
		}
		trees.pop();
	}
}

void buildChild(vector<int>::iterator prestart, vector<int>::iterator preend, vector<int>::iterator instart, vector<int>::iterator inend, TreeNode* root) {
	root->val = *prestart;
	int num = 0;
	for (vector<int>::iterator i = instart; i != inend; i++) {
		if (*prestart == *i) {
			num = i - instart;
			break;
		}
	}
	//重建STL太过浪费时间,而且占用内存,可以直接传递首尾迭代器
	//vector<int> prelchild(preorder.begin() + 1, preorder.begin() + num +1);
	//vector<int> prerchild(preorder.begin() + num + 1, preorder.end());
	//vector<int> inlchild(inorder.begin(), inorder.begin()+num);
	//vector<int> inrchild(inorder.begin() + num + 1, inorder.end());

	if (num!=0) {
		root->left = new TreeNode();
		buildChild(prestart + 1, prestart + num + 1, instart, instart + num, root->left);
	}
	if (prestart + num + 1 != preend) {
		root->right = new TreeNode();
		buildChild(prestart + num + 1, preend, instart + num + 1, inend, root->right);
	}
	
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	if (preorder.empty()) {
		return NULL;
	}
	TreeNode* rroot = new TreeNode();
	buildChild(preorder.begin(),preorder.end(),inorder.begin(), inorder.end(), rroot);
	return rroot;
}

