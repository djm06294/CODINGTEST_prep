// 24.05.01 WED
// JooYoung Kim
// "[S/W 문제해결 응용] 1일차 - 단순 2진 암호코드"
// https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=3&contestProbId=AV15FZuqAL4CFAYD&categoryId=AV15FZuqAL4CFAYD&categoryType=CODE&problemTitle=&orderBy=INQUERY_COUNT&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=1

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string codes[] = {"0001101", "0011001", "0010011", "0111101", "0100011", "0110001", "0101111", "0111011", "0110111", "0001011"};

// 길이 m의 0으로 된 string 반환
string makezero(int m) {
    string str = "";
    for(int i=0; i<m; i++)
        str.append("0");
    
    return str;
}

// 0/1로 되어있는 string을 실제 숫자로 바꿔 반환
string code2Num(string str) {
    string number = "";
    int min_idx=str.length();

    for(int i=0; i<10; i++) {
        int idx = str.find(codes[i]);
        if(idx!=-1 && idx<min_idx) min_idx = idx;
    }

    str = str.substr(min_idx);
    // cout<<str<<endl;

    while(1) {
        for(int i=0; i<7*8; i+=7) {
            for(int j=0; j<10; j++) {
                if(str.substr(i,7) == codes[j]) {
                    number.append(to_string(j));
                }
            }
        }
        
        if(number.length() == 8) {
            break;
        } else {
            number = "";
            str = str.substr(2);
        }
    }

    return number;
}

int checkCode(string num) {
    int sumOdd=0, sumEven=0;
    for(int i=0; i<8; i+=2) {
        sumOdd += num[i] - '0';
        sumEven += num[i+1] - '0';
    }

    if((sumOdd*3 + sumEven)%10 == 0) return sumOdd+sumEven;
    else return 0;
}

int main() {
    ifstream inputTxt("C:\\Users\\jooyoung\\Downloads\\input (2).txt", ios_base::in);
    if(inputTxt.is_open()) { cin.rdbuf(inputTxt.rdbuf()); }
    
    int T;
    cin>>T;

    for(int t=1; t<=T; t++) {
        string str, strzero;
        int i=0, N, M;
        cin>>N>>M;
        strzero = makezero(M);

        while(i<N) {
            cin>>str;
            i++;
            if(str!=strzero) {
                string tmp;
                while(i<N) {
                    cin>>tmp;
                    i++;
                }
            }
        }

        cout<<"#"<<t<<" "<<checkCode(code2Num(str))<<"\n";
    }

}