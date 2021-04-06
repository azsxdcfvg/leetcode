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


void BFS(TreeNode* root);
void buildChild(vector<int>& preorder, vector<int>& inorder, TreeNode* root) {
	
	int rootnum = preorder[0];
	root->val = rootnum;
	int num = 0;
	for (vector<int>::iterator i = inorder.begin(); i != inorder.end(); i++) {
		if (rootnum == *i) {
			num = i - inorder.begin();
			break;
		}
	}
	vector<int> prelchild(preorder.begin() + 1, preorder.begin() + num +1);
	vector<int> prerchild(preorder.begin() + num + 1, preorder.end());
	vector<int> inlchild(inorder.begin(), inorder.begin()+num);
	vector<int> inrchild(inorder.begin() + num + 1, inorder.end());

	
	
	if (!prelchild.empty()) {
		root->left = new TreeNode();
		buildChild(prelchild, inlchild, root->left);
	}
	if (!prerchild.empty()) {
		root->right = new TreeNode();
		buildChild(prerchild, inrchild, root->right);
	}
	
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	if (preorder.empty()) {
		return NULL;
	}
	TreeNode* rroot = new TreeNode();
	buildChild(preorder, inorder, rroot);
	return rroot;
}

//≤‚ ‘’˝»∑–‘
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