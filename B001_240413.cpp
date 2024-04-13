// 24.04.13 SAT
//JooYoung Kim
// https://www.acmicpc.net/problem/2606

#include <iostream>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
    if(a.first!=b.first) return a.first<b.first;
    else return a.second<b.second;
}

int main() {
    set<int> virusComp;
    vector<pair<int,int>> pairs;
    int totcomp, pairNum;
    cin>>totcomp>>pairNum;

    while(pairNum--) {
        int a,b;
        cin>>a>>b;
        if(a<b) pairs.push_back(make_pair(a,b));
        else pairs.push_back(make_pair(b,a));
    }

    sort(pairs.begin(), pairs.end(), cmp);

    for(auto i:pairs) {
        if(i.first==1 || i.second==1 || virusComp.count(i.first) || virusComp.count(i.second)) {
            virusComp.insert(i.first);
            virusComp.insert(i.second);
        }
    }

    cout<<virusComp.size()-1;
}
