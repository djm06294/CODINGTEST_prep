// 24.01.26 FRI
// JooYoung Kim
// https://www.acmicpc.net/problem/11721

// too easy

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin>>str;
    int len = str.length();

    for(int i=0; i<len; i++) {
        printf("%c", str[i]);
        if((i+1)%10 == 0) printf("\n");
    }
}