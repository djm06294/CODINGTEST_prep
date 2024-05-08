// 24.05.07 TUE
// JooYoung Kim
// "부분 수열의 합"
// https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=3&contestProbId=AV7IzvG6EksDFAXB&categoryId=AV7IzvG6EksDFAXB&categoryType=CODE&problemTitle=&orderBy=RECOMMEND_COUNT&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dfs(int i, int result, int k) {
    if(result == k) 
        return dfs(i+1, )
}

int findSumCases(vector<int>& v, int k) {
    while(v.back() > k) v.pop_back();
    return dfs(0, k);
}

int main() {
    int T;
    cin>>T;

    for(int t=1; t<=T; t++) {
        int N, K;
        vector<int> array;
        cin>>N>>K;

        for(int i=0; i<N; i++) {
            int tmp;
            cin>>tmp;
            array.push_back(tmp);
        }
        
        sort(array.begin(), array.end());

        cout<<"#"<<t<<" "<<findSumCases(array, K)<<"\n";
    }
}