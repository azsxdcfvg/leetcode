#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std;
string longestPalindrome(string s) {
    int maxlen = 0;
    int lmax = 0, rmax = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        int curlen = 1;
        if (curlen > maxlen) {
            lmax = rmax = i;
            maxlen = curlen;
        }
        int j = 1;
        for (; j <= min(i, n - i); j++) {
            if (s[i - j] != s[i + j] && curlen > maxlen) {
                maxlen = 2 * j + 1;
                lmax = i - j;
                rmax = i + j;
            }
            else {
                curlen++;
            }
        }
        if (curlen > maxlen) {
            maxlen = 2 * j + 1;
            lmax = i - j;
            rmax = i + j;
        }
    }
    return string(s.begin() + lmax, s.begin() + rmax + 1);
}