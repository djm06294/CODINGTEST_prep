// 24.02.10 SAT
// JOOYOUNG KIM
// https://www.acmicpc.net/problem/2108

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mean(vector<int>& v) {
    double ans=0;
    for(auto& i:v)
        ans += i;
        
    if(ans<0) ans = ans/v.size() - 0.5;     // 반올림
    else ans = ans/v.size() + 0.5;
    
    return (int)ans; 
}

int middle(vector<int>& v) {
    return v[v.size()/2];
}

int many(vector<int>& v) {
    vector<pair<int,int>> pairV;
    int size = v.size(), count=0;
    
    v.push_back(4001);
    for(int i=0; i<size; i++) {
        if(v[i] == v[i+1]) count++;
        else {
            pairV.push_back(make_pair(v[i],count+1));
            count = 0;
        }
    }
    v.pop_back();

    sort(pairV.begin(), pairV.end(), [](const pair<int,int>& a, const pair<int,int>& b) { if(a.second==b.second) return a.first<b.first; else return a.second>b.second; });
    for(auto& p:pairV) cout<<p.first<<" "<<p.second<<endl;

    if(pairV[0].second == pairV[1].second) 
        return pairV[1].first;
    else 
        return pairV[0].first;
}

int range(vector<int>& v) {
    return v[v.size()-1] - v[0];
}

int main() {
    // 204ms -> 76ms
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    vector<int> v;
    int N;
    cin>>N;

    while(N--) {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    cout<<mean(v)<<"\n";
    cout<<middle(v)<<"\n";
    cout<<many(v)<<"\n";
    cout<<range(v)<<"\n";    
}