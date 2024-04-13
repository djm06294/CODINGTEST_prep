// 24.02.08 THU
// JOOYOUNG KIM
// https://www.acmicpc.net/problem/2217

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v;
    int N;
    cin>>N;

    while(N--) {
        int weight;
        cin>>weight;
        v.push_back(weight);
    }

    sort(v.begin(), v.end(), [](const int& a, const int& b) { return a>b; });

    int max = v[0];

    for(int i=1; i<v.size(); i++) {
        if(v[i] * (i+1) > max)
            max = v[i] * (i+1);
    }

    cout<<max;
}

