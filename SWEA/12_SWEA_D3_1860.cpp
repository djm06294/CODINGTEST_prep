// 24.05.07 TUE
// JooYoung Kim
// "진기의 최고급 붕어빵"
// https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=3&contestProbId=AV5LsaaqDzYDFAXc&categoryId=AV5LsaaqDzYDFAXc&categoryType=CODE&problemTitle=&orderBy=RECOMMEND_COUNT&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=2

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

bool checkPossible(int v[], int n, int k) {
    int time=0, breadNum=0, i=0;
    if(v[0]==0) return false;

    while(1) {
        time++;
        breadNum += k;

        while(v[i] == time) {
            breadNum--;
            if(breadNum<0) return false;

            i++;
            if(i==n) return true;           
        }
    }
    return true;    
}

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    ifstream inputTxt("C:\\Users\\jooyoung\\Downloads\\input (7).txt", ios_base::in);
    if(inputTxt.is_open()) { cin.rdbuf(inputTxt.rdbuf()); }

    int T;
    cin>>T;
    int v[100];

    for(int t=1; t<T; t++) {
        int N, M, K;
        cin>>N>>M>>K;

        for(int i=0; i<N; i++) {
            int tmp;
            cin>>tmp;
            v[i] = tmp/M;
        }

        sort(v, v + N);

        if(checkPossible(v, N, K)) {
            cout<<"#"<<t<<" Possible\n";
        } else {
            cout<<"#"<<t<<" Impossible\n";
        }
    }
}