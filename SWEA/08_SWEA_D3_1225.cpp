// 24.05.02 THU
// JooYoung Kim
// "[S/W 문제해결 기본] 7일차 - 암호생성기"
// https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=3&contestProbId=AV14uWl6AF0CFAYD&categoryId=AV14uWl6AF0CFAYD&categoryType=CODE&problemTitle=&orderBy=INQUERY_COUNT&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=1

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inputTxt("C:\\Users\\jooyoung\\Downloads\\input (3).txt", ios_base::in);
    if(inputTxt.is_open()) { cin.rdbuf(inputTxt.rdbuf()); }

    int nums[10];

    for(int t=1; t<=10; t++) {
        int idx = 0, sub = 1;
        cin>>t;

        for(int i=0; i<8; i++)
            cin>>nums[i];

        while(1) {
            nums[idx] -= sub;

            if(nums[idx] <= 0) 
                break;
            
            sub++; idx++;
            if(sub==6) sub=1;
            if(idx==8) idx=0;
        }

        cout<<"#"<<t<<" ";

        int i = idx+1;
        while(i != idx) {
            cout<<nums[i++]<<" ";
            if(i==8) i=0;
        }

        cout<<0<<"\n";
    }

}