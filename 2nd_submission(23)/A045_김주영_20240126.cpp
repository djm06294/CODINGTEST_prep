// 24.01.26 FRI
// JooYoung Kim
// https://www.acmicpc.net/problem/1157

#include <iostream>
#include <string>
using namespace std;

int main() {
    int alpabets[26]={0};
    int maxChar=0, maxCount=0;
    string str;
    cin>>str;

    for(auto& i:str) {
        i = toupper(i);
        alpabets[i-'A']++;
        if(alpabets[i-'A'] > maxCount) {
            maxCount = alpabets[i-'A'];
            maxChar = i;
        } else if (alpabets[i-'A'] == maxCount) {
            maxChar = 0;
        } 
    }

    if(maxChar==0) printf("?");
    else printf("%c", maxChar);    
}