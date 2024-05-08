// 24.05.04 SAT
// JooYoung Kim
// "[S/W 문제해결 기본] 5일차 - Magnetic"
// https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=3&contestProbId=AV14hwZqABsCFAYD&categoryId=AV14hwZqABsCFAYD&categoryType=CODE&problemTitle=&orderBy=INQUERY_COUNT&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=2

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void readColumns(string col[]) {
    char c;

    for(int i=0; i<100; i++) {
        for(int j=0; j<100; j++) {
            cin>>c;
            if(c!='0') col[j] += c;
            // cout<<j<<" "<<col[j]<<endl;
        }
    }

    for(int i=0; i<100; i++) {
            // cout<<i<<" "<<col[i]<<endl;
    }
}

int countDeadLock(string& line) {
    int idx=-1, count=0;

    while(1) {
        idx = line.find("12", idx+1);

        if(idx==-1) break;
        else count++;
    }

    return count;
}

int main() {
    ifstream inputTxt("C:\\Users\\jooyoung\\Downloads\\input (6).txt", ios_base::in);
    if(inputTxt.is_open()) { cin.rdbuf(inputTxt.rdbuf()); }

    int T = 10;
    string columns[100] = "";   //이래도 초기화는 되는데 어차피 for문에서 초기화 해줘야해서 무의미하긴 함!

    for(int t=1; t<=T; t++) {
        int dump, count=0;    
        cin>>dump;

        for(int i=0; i<100; i++) 
            columns[i] = "";
        
        readColumns(columns);        

        for(int i=0; i<100; i++) {
            count += countDeadLock(columns[i]);
        }

        cout<<"#"<<t<<" "<<count<<"\n";
    }
}