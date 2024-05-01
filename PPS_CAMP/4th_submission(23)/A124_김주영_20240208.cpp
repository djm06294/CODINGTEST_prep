// 24.02.08 THU
// JOOYOUNG KIM
// https://www.acmicpc.net/problem/11653

// very easy

#include <iostream>
using namespace std;

int main() {
    int N;
    cin>>N;

    for(int i=2; N!=1; i++) {
        while(N%i==0) {
            cout<<i<<endl;
            N = N/i;
        }
    }
}