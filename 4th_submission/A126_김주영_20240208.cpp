// 24.02.08 THU
// JOOYOUNG KIM
// https://www.acmicpc.net/problem/1065

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isHan(int n) {
    if(n/100==0) return true;

    int d1 = (n%100)/10 - n%10;
    while(n/100!=0) {
        n /= 10;
        int d2 = (n%100)/10 - n%10;
        if(d1 != d2) return false;
    }

    return true;
}

int main() {
    int N;
    cin>>N;

    int count=0;

    for(int i=1; i<=N; i++) {
        if(isHan(i))
            count++;
    }

    cout<<count;    
}
