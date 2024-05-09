// 24.05.07 TUE -> 24.05.09 THR
// JooYoung Kim
// "부분 수열의 합"
// https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=3&contestProbId=AV7IzvG6EksDFAXB&categoryId=AV7IzvG6EksDFAXB&categoryType=CODE&problemTitle=&orderBy=RECOMMEND_COUNT&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=2
// 알고리즘 참고: https://velog.io/@seungjae/SWEA-2817%EB%B2%88-%EB%B6%80%EB%B6%84%EC%88%98%EC%97%B4%EC%9D%98-%ED%95%A9-Python-DFS-%EC%99%84%EC%A0%84%ED%83%90%EC%83%89-D3 (DFS)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int array[20];
int N, K;

int dfs(int result, int i) {
    if(result == K)
        return 1;
    if(result>K || i==N)
        return 0;
    
    return dfs(result+array[i], i+1) + dfs(result, i+1);    
}

int main() {
    int T;
    cin>>T;

    for(int t=1; t<=T; t++) {
        cin>>N>>K;

        for(int i=0; i<N; i++)
            cin>>array[i];

        cout<<"#"<<t<<" "<<dfs(0, 0)<<"\n";
    }
}