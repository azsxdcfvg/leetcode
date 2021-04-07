#pragma once
/*
//Õ»Òç³öÁË
int fib(int n) {
    
    int fir = 0;
    int sec = 1;
    if (n == 0 || n == 1) return n;
    else {
        do {
            fir += sec;
            int temp = sec;
            sec = fir;
            fir = temp;
            n--;
        } while (n >= 2);
        return sec;
    }
}
 */
int fib(int n) {

    int fir = 0;
    int sec = 1;
    if (n == 0 || n == 1) return n;
    else {
        do {
            fir += sec;
            int temp = sec % 1000000007;
            sec = fir % 1000000007;
            fir = temp;
            n--;
        } while (n >= 2);
        return sec % 1000000007;
    }
}