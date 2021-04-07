#include"5最长回文子串.h"
#include"6Z字形变换.h"
#include"7整数反转.h"
#include"8重建二叉树.h"
#include"10-1斐波那契数.h"
#include"12矩阵中的路径.h"
using namespace std;
int main() {
    string word = "AAB";
    vector<vector<char>> board{ {'C', 'A', 'A'},{'A', 'A', 'A' }, {'B', 'C', 'D'} };
    cout << exist(board, word) << endl;;
}