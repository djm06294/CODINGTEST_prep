// 24.04.16 TUE
// JooYoung Kim
// "[S/W 문제해결 기본] 1일차 - View"
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV134DPqAA8CFAYh&categoryId=AV134DPqAA8CFAYh&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=&pageSize=10&pageIndex=1

#include <iostream>
using namespace std;

int maxFour(int a, int b, int c, int d) {
    int tmp1 = a>b?a:b;
    int tmp2 = c>d?c:d;
    return tmp1>tmp2?tmp1:tmp2;
}

int main() {
    int N;

    for(int i=0; i<10; i++) {
        cin>>N;
        int* h = new int[N];
        int answer=0;

        for(int j=0; j<N; j++)
            cin>>h[j];
        
        for(int j=2; j<N-2; j++) {
            int max = maxFour(h[j-2], h[j-1], h[j+1], h[j+2]);
            if(max<h[j]) answer+=h[j]-max;
        }

        cout<<"#"<<i+1<<" "<<answer<<"\n";
    }
}