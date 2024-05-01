// 24.01.25 THU
// JooYoung Kim
// https://www.acmicpc.net/problem/2775

#include <iostream>
using namespace std;


int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, k, n;
    cin>>T;
    while(T--) {
        cin>>k>>n;
        int floor_under_k[14];
        for(int i=0;i<n;i++) floor_under_k[i] = i+1;

        for(int fl=0; fl<k; fl++) {
            for(int r=1; r<n; r++)
                floor_under_k[r] = floor_under_k[r-1] + floor_under_k[r];
        }

        cout<<floor_under_k[n-1]<<endl;
    }
}

// 0: 1 2 3 4 5
// 1: 1 3 6 10 15
// 2: 1 4 10 20 35