// 24.01.31 TUE
// JooYoung Kim
// https://www.acmicpc.net/problem/2822

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool secondCompare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}

int main() {
    vector<pair<int, int>> scores;
    int sum = 0;

    for(int i=0;i<8; i++) {
        int tmp;
        cin>>tmp;
        scores.push_back(make_pair(tmp,i+1));
    }

    sort(scores.begin(), scores.end(), greater<>());

    for(int i=0; i<8; i++) {
        if(i<5) sum+=scores[i].first;
        else scores.pop_back();
    }

    cout<<sum<<endl;
    sort(scores.begin(), scores.end(), secondCompare);

    for(int i=0; i<5; i++)
        cout<<scores[i].second<<" ";    
    
}

