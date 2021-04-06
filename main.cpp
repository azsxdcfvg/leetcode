#include"5最长回文子串.h"
#include"6Z字形变换.h"
#include"7整数反转.h"

using namespace std;
int main() {
    int temp = 123 % 10;
    int count = 0;
    count = count << 1 + count << 3 + temp;
    cout << count << endl;
}