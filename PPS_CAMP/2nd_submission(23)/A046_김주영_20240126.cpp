// 24.01.26 FRI
// JooYoung Kim
// https://www.acmicpc.net/problem/1159

// 잘 구현한거 같진 않음

#include <iostream>
#include <string>
using namespace std;

int main() {
    int alphabets[26]={0};
    string tmp;
    int N;
    cin>>N;
    while(N--) {
        cin>>tmp;
        alphabets[tmp[0]-'a']++;
    }

    bool check = 0;
    for(int i=0; i<26; i++) {
        if(alphabets[i] >= 5) {
            cout<<(char)(i + 'a');
            check = 1;
        }
    }
    if(!check) cout<<"PREDAJA";
}