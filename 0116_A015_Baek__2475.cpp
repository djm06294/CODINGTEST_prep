// 24.01.16 TUE
// Jooyoung Kim
// https://www.acmicpc.net/problem/2475

// very easy

#include <iostream>
using namespace std;

int main() {
    int tmp, sum=0;
    for(int i=0; i<5; i++) {
        cin>>tmp;
        sum+=tmp*tmp;
    }

    cout<<sum%10;
}