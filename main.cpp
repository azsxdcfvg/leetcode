#include"5������Ӵ�.h"
#include"6Z���α任.h"
#include"7������ת.h"

using namespace std;
int main() {
    int temp = 123 % 10;
    int count = 0;
    count = count << 1 + count << 3 + temp;
    cout << count << endl;
}