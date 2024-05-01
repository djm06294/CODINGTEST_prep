// 24.04.16 TUE
// JooYoung Kim
// "공평한 분배"
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AY6cg0MKeVkDFAXt&categoryId=AY6cg0MKeVkDFAXt&categoryType=CODE&problemTitle=&orderBy=RECOMMEND_COUNT&selectCodeLang=PYTHON&select-1=&pageSize=10&pageIndex=1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int T, N, K;
    cin>>T;

    for(int t=1; t<=T; t++) {
        cin>>N>>K;
        vector<int> pockets;
        int min=1000000001;

        while(N--) {
            int tmp;
            cin>>tmp;
            pockets.push_back(tmp);
        }

        sort(pockets.rbegin(), pockets.rend()); //내림차순

        for(int i=0; i<pockets.size()-K+1; i++) {
            int sub = pockets[i]-pockets[i+K-1];
            if(sub<min) min = sub;
        }

        cout<<"#"<<t<<" "<<min<<"\n";       

    }
}

