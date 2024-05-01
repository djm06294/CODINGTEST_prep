// 24.02.08 THU
// JOOYOUNG KIM
// https://www.acmicpc.net/problem/1463

// 이게.. very easy?? 내 머리가 이상한가?

#include <iostream>
using namespace std;

int makeOne(int n) {
    if(n==1) return 0;

    if(n%3==0) {
        return makeOne(n/3) + 1;
    } else if(n%2==0) {
        if((n-1)%3==0) return makeOne(n-1) + 1;
        else return makeOne(n/2) + 1;
    } else {
        return makeOne(n-1) + 1;
    }
}

int main() {
    int N;
    cin>>N;

    cout<<makeOne(N);
}