// 24.01.27 SAT
// JooYoung Kim
// https://www.acmicpc.net/problem/5598

// Too eassyy

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin>>str;
    int len = str.length();

    for(int i=0; i<len; i++) {
        if(str[i] < 'D') str[i] = str[i]+26;
        str[i]-=3;
    }

    cout<<str;
}