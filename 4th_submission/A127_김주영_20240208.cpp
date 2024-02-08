// 24.02.08 THU
// JOOYOUNG KIM
// https://www.acmicpc.net/problem/1934

#include <iostream>
using namespace std;

int main() {
    int T;
    cin>>T;

    while(T--) {
        int min1, min2;
        int a, b;
        cin>>a>>b;

        for(int i=1; ; i++) {
            if((a*i)%b == 0) {      // a < b라고 가정
                cout<<a*i<<endl;
                break;
            }   
        }
    }

}