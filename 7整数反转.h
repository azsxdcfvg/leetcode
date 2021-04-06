#pragma once
#include<iostream>

int reverse(int x) {
    int min = -(1 << 30) * 2;
    int max = -(min + 1);
    if (x == (-(1 << 30)) * 2) {
        return 0;
    }
    int count = 0;
    while (x != 0) {
        int temp = x % 10;

        if (count > 0 && (max - temp) / 10 < count) return 0;
        if (count<0 && (min - temp) / 10 > count) return 0;
        count = count*10 + temp;
        x = x / 10;
    }

    return count;
}