// 24.04.23 TUE
// JooYoung Kim
// "농작물 수확하기"
// https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=3&contestProbId=AV7GLXqKAWYDFAXB&categoryId=AV7GLXqKAWYDFAXB&categoryType=CODE&problemTitle=&orderBy=RECOMMEND_COUNT&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=1

#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin>>T;

    for(int t=1; t<=T; t++) {
        int N;
        cin>>N;
        
        string str;
        int* farm = new int[N];
        int sum = 0;

        for(int i=0; i<N; i++) {
            
            cin>>str;
            for(int j=0; j<N; j++)
                farm[j] = str[j] - '0';

            sum += farm[N/2];
                
            if(i<=N/2) {
                for(int j=1; j<=i; j++) {
                    sum += farm[N/2+j];
                    sum += farm[N/2-j];
                }
            } else {
                for(int j=1; j<N-i; j++) {
                    sum += farm[N/2+j];
                    sum += farm[N/2-j];
                }
            }
        }

        cout<<"#"<<t<<" "<<sum<<"\n";
    }
}