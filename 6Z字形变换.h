#pragma once
/*
将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
P   A   H   N
A P L S I I G
Y   I   R
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zigzag-conversion
*/
#include<string>
#include<iostream>
#include<vector>
using namespace std;

string convert(string s, int numRows) {
	if (numRows == 1 || numRows>=s.length()) {
		return s;
	}
	int znum = 2 * numRows - 2;
	int* z = (int*)malloc(sizeof(int) * (znum));//只需要一个Z就可以构造出后面的内容
	for (int i = 1; i < numRows - 1; i++) {
		z[2 * i - 1] = i + 1;
		z[2 * i] = znum - i + 1;
	}
	z[0] = 1;
	z[znum - 1] = numRows;
	//通过z顺序构造完整串
	string news = "";
	int length = s.length();
	int i = 0;
	while (i < length) {
		news.push_back(s[i]);
		i += znum;
	}
	for (int i = 1; i < znum - 1; i += 2) {
		int j = 0;
		while (z[i] + j - 1< length && z[i + 1] + j - 1 < length) {
			news.push_back(s[z[i] - 1 + j]);
			news.push_back(s[z[i + 1] + j - 1]);
			j += znum;
		}
		while (z[i] + j - 1 < length) {
			news.push_back(s[z[i] - 1 + j]);
			j += znum;
		}
	}
	i = numRows - 1;
	while (i < length) {
		news.push_back(s[i]);
		i += znum;
	}
	return news;
}
/*
对numRows == 1以及>s.length()的边界情况没有考虑
思路上有点麻烦,直接用余数就可以对应,例如
对于n行的, s中的第i个字符：
对余数进行判断
i%(2n-2) == 0 ----> row0
i%(2n-2) == 1 II i%(2n-2-1) == 2----> row1
i%(2n-2) == 2 || i%(2n-2-2) == 2 ----> row2
...
i%(2n-2) == n-1 ----> row(n-1)
==>
对 k = i%(2n-2)进行判断

k<=n-1时候，s[i]就属于第k行
k>n-1时候，s[i]就属于2n-2-k行
*/