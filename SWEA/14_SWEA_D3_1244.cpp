// 24.04.17 WED -> 24.05.09 THR
// JooYoung Kim
// "[S/W 문제해결 응용] 2일차 - 최대 상금"
// https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=3&contestProbId=AV15Khn6AN0CFAYD&categoryId=AV15Khn6AN0CFAYD&categoryType=CODE&problemTitle=&orderBy=RECOMMEND_COUNT&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=1

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

string swap(string s, int i, int j) {
    char tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
    return s;
}

string findMaxSwapNumber(string s, int n, int idx) {
    if(n==0) {
        // cout<<"returning "<<s<<endl;
        return s;
    }
    string max_str = "", tmp_str;
    int len = s.length();   

    for(int i=idx; i<len-1; i++) {

        int max = 0;
        for(int j=i+1; j<len; j++)
            if(s[j] > max) max = s[j];

        for(int j=i+1; j<len; j++) {
            if((s[j]==max && s[i]<=s[j]) || i==len-2) {
                tmp_str = findMaxSwapNumber(swap(s, i, j), n-1, i);
                max_str = tmp_str.compare(max_str)<0 ? max_str: tmp_str;
            }
        }
    }

    // cout<<"maxstr "<<max_str<<endl;
    return max_str;
}

int main() {
    ifstream inputTxt("C:\\Users\\jooyoung\\Downloads\\input (8).txt", ios_base::in);
    if(inputTxt.is_open()) { cin.rdbuf(inputTxt.rdbuf()); }

    int T;
    cin>>T;
    
    for(int t=1; t<=T; t++) {
        string str;
        int swapNum;
        cin>>str>>swapNum;

        // if(t==4)
        cout<<"#"<<t<<" "<<findMaxSwapNumber(str, swapNum, 0)<<"\n";
    }

}