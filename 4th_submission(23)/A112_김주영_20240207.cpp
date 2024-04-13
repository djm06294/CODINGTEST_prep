// 24.02.07 WED
// JOOYOUNG KIM
// https://www.acmicpc.net/problem/1049

#include <iostream>
using namespace std;

int main() {
    int N, M;
    int minPack=1000, minOne=1000;
    int sum = 0;
    cin>>N>>M;

    while(M--) {
        int a, b;
        cin>>a>>b;

        if(a < minPack) minPack = a;
        if(b < minOne) minOne = b;
    }

    if(6*minOne <= minPack) {
        cout<< N*minOne;
        return 0;
    }

    for(int i=0; i<N;) {
        if(i+6 <= N || minPack <= minOne*(N-i)) {
            sum+=minPack;
            i += 6;
        } else {
            sum += minOne*(N-i);
            i += N-i;
        }
    }

    cout<<sum<<endl;
}