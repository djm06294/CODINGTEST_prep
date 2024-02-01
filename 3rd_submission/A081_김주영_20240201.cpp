// 24.02.01 THU
// JOOYOUNG KIM
// https://www.acmicpc.net/problem/2693

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin>>T;

    while(T--) {
        vector<int> v;
        for(int i=0; i<10; i++) {
            int tmp;
            cin>>tmp;
            v.push_back(tmp);
        }
        sort(v.begin(), v.end(), greater<>());

        cout<<v[2]<<endl;
    }
}