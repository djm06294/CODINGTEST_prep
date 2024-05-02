// 24.05.03 FRI
// JooYoung Kim
// "원재의 메모리 복구하기"
// https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=3&contestProbId=AV19AcoKI9sCFAZN&categoryId=AV19AcoKI9sCFAZN&categoryType=CODE&problemTitle=&orderBy=INQUERY_COUNT&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=1

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int countChange(string& str) {
    cout<<str<<endl;
    int count=0, idx=-1;

    if(str[0]=='1') count++;

    while(1) {
        idx = str.find("01", idx+1);
        if(idx==-1) break;
        else count++;
    }

    idx = -1;
    while(1) {
        idx = str.find("10", idx+1);
        if(idx==-1) break;
        else count++;
    }

    return count;
}

int main() {
    ifstream inputTxt("C:\\Users\\jooyoung\\Downloads\\input (5).txt", ios_base::in);
    if(inputTxt.is_open()) { cin.rdbuf(inputTxt.rdbuf()); }
    int T;
    cin>>T;

    for(int t=1; t<=T; t++) {
        string memory;
        cin>>memory;

        cout<<"#"<<t<<" "<<countChange(memory)<<"\n";
    }
}