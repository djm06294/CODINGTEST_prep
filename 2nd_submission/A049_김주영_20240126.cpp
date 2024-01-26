// 24.01.26 FRI
// JooYoung Kim
// https://www.acmicpc.net/problem/4659

// 좀 더 깔끔하게 할 수 있을까?

#include <iostream>
#include <string>
using namespace std;

int main() {
    string pswd;

    while(1) {
        cin>>pswd;
        bool accept = true;
        bool req1 = false;
        int req2 = 0; //모음은 +1씩, 자음은 -1씩 세기
        char prev = '0';
        
        if(!pswd.compare("end")) break;

        for(auto i:pswd) {
            // 조건#1 & #2
            if(i=='a'||i=='e'||i=='i'||i=='o'||i=='u') {
                req1 = true;
                if(req2 >= 0) req2++;
                else req2 = 1;
            }  else {
                if(req2 <= 0) req2--;
                else req2 = -1;
            }

            if(req2==3 || req2==-3) {
                accept = false;
                break;
            }

            // 조건#3
            if(prev == i && i!='e' && i!='o') {
                accept = false;
                break;
            }
            prev = i;
        }
        if(req1 && accept) printf("<%s> is acceptable.\n", pswd.c_str());
        else printf("<%s> is not acceptable.\n", pswd.c_str());

    }
}
