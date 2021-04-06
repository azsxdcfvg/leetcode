#include"5最长回文子串.h"
#include"6Z字形变换.h"
#include"7整数反转.h"
#include"8重建二叉树.h"
using namespace std;
int main() {
    TreeNode* root;
    vector<int> preorder = { 3,9,20,15,7 };
    vector<int> inorder = { 9,3,15,20,7 };
    root = buildTree(preorder, inorder);
    BFS(root);
}