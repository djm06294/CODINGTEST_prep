// 24.04.16 TUE
// JooYoung Kim
// "서로소 그리드"
// 실패!
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AY6ci8cKecUDFAXt&categoryId=AY6ci8cKecUDFAXt&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=&pageSize=10&pageIndex=1

#include <iostream>
#include <string>
#include <thread>
using namespace std;

int isGCD(int a, int b, char c) {
    int A = a>b?a:b;
    int B = a>b?b:a;

    while(B!=0) {
        if(A%B==0) {
            if(B==1 && c=="1") return true;
            else if(B!=1 && c=="?") return true;
            else return false;
        }        
        A = B;
        B = A%B;
    }
}

int main() {
    int T, N, k=0;
    cin>>T;

    for(int t=1; t<=T; t++) {
        cin>>N;
        string* arr = new string[N];
        
        for(int i=0; i<N; i++) {
            cin>>arr[i];

            for(int j=0; j<N; j++) {
                if(!isGCD(i+k, j+k, arr[i][j])) {
                    k++;
                    i=0; j=0;
                }
            }
        }


    }
}
