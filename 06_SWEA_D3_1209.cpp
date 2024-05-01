// 24.04.30 TUE
// JooYoung Kim
// "[S/W 문제해결 기본] 2일차 - Sum"
// https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=3&contestProbId=AV13_BWKACUCFAYh&categoryId=AV13_BWKACUCFAYh&categoryType=CODE&problemTitle=&orderBy=INQUERY_COUNT&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=1

#include <iostream>
#include <fstream>
using namespace std;
#define SIZE 100

int findMax(int baeyol[][SIZE]) {
    int max = 0;
    int sum3=0, sum4=0;

    for(int i=0; i<SIZE; i++) {
        int sum1=0, sum2=0;
        sum3 += baeyol[i][i];           // 좌-우 대각선

        for(int j=0; j<SIZE; j++) {
            sum1 += baeyol[i][j];       // 가로줄 합
            sum2 += baeyol[j][i];       // 세로줄 합
            if(i+j==SIZE-1) sum4 += baeyol[i][j];   // 우-좌 대각선
        }

        if(sum1>max) max = sum1;
        if(sum2>max) max = sum2;
    }
    
    if(sum3>max) max = sum3;
    if(sum4>max) max = sum4;

    return max;    
}

int main() {
    int T;
    int baeyol[SIZE][SIZE];

    ifstream inputTxt("C:\\Users\\jooyoung\\Downloads\\input (1).txt", ios_base::in);
    if(inputTxt.is_open())
        cin.rdbuf(inputTxt.rdbuf());

    for(int t=1; t<=10; t++) {
        cin>>T;
        for(int i=0; i<100; i++) {
            for(int j=0; j<100; j++) {
                cin>>baeyol[i][j];
            }
        }

        cout<<"#"<<t<<" "<<findMax(baeyol)<<"\n";

    }
    
}