#include"5������Ӵ�.h"
#include"6Z���α任.h"
#include"7������ת.h"
#include"8�ؽ�������.h"
using namespace std;
int main() {
    TreeNode* root;
    vector<int> preorder = { 3,9,20,15,7 };
    vector<int> inorder = { 9,3,15,20,7 };
    root = buildTree(preorder, inorder);
    BFS(root);
}