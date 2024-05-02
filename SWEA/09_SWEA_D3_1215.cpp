// 24.05.02 THU
// JooYoung Kim
// "[S/W 문제해결 기본] 3일차 - 회문1"
// https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=3&contestProbId=AV14QpAaAAwCFAYi&categoryId=AV14QpAaAAwCFAYi&categoryType=CODE&problemTitle=&orderBy=INQUERY_COUNT&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=1

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isPalindrome(string str) {
    int len = str.length();
    if(len<=1) return true;

    if(str.front()==str.back()) 
        return isPalindrome(str.substr(1,len-2));
    else 
        return false;
}

int countPalindrome(int l, string board[8]) {
    int count = 0;

    for(int i=0; i<8; i++) {
        for(int j=0; j<=8-l; j++) {

            // 가로로 확인
            if(isPalindrome(board[i].substr(j,l)))
                count++;

            // cout<<"가로"<<board[i].substr(j,l)<<endl;

            // 세로로 확인
            string tmp = "";
            for(int k=j; k<j+l; k++) {
                tmp += board[k][i];
            }            
            if(isPalindrome(tmp)) count++;
            // cout<<"세로"<<tmp<<endl;

            // cout<<count<<endl;
        }
    }

    return count;    
}


int main() {
    ifstream inputTxt("C:\\Users\\jooyoung\\Downloads\\input (4).txt", ios_base::in);
    if(inputTxt.is_open()) { cin.rdbuf(inputTxt.rdbuf()); }

    int l;
    string board[8];

    for(int t=1; t<=10; t++) {
        cin>>l;

        for(int i=0; i<8; i++)
            cin>>board[i];

        cout<<"#"<<t<<" "<<countPalindrome(l, board)<<"\n";        
    }
}