// 24.01.26 FRI
// JooYoung Kim
// https://www.acmicpc.net/problem/1316

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str, tmp = "";
    int N, count=0;
    cin>>N;
    
    while(N--) {
        cin>>str;
        char prev = str[0];
        tmp += str[0];

        for(auto& i: str) {
            if(prev != i) {
                if(tmp.find(i) == string::npos) {
                    tmp += i;
                } else {
                    count--;
                    break;
                }
                prev = i;
            }          
        }
        tmp = "";
        count++;        
    }
    cout<<count;
}