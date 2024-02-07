// 24.02.07 WED
// JOOYOUNG KIM
// https://www.acmicpc.net/problem/9546

#include <iostream>
using namespace std;

int main() {
    int T, k;
    cin>>T;
    while(T--) {
        int people = 0;
        cin>>k;

        while(k--) {
            people = people*2 +1;
        }
        cout<<people<<endl;
    }
}
