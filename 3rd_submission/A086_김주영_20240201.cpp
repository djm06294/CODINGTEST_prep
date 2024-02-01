// 24.02.01 THU
// JOOYOUNG KIM
// https://www.acmicpc.net/problem/1755

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string toDictionaryOrder(int n) {
    string tmp="";
    while(n!=0) {
        switch(n%10) {
            case 0: 
                tmp='9'+tmp;
                break;
            case 1:
                tmp='4'+tmp;
                break;
            case 2:
                tmp='8'+tmp;
                break;
            case 3:
                tmp='7'+tmp;
                break;
            case 4:
                tmp='2'+tmp;
                break;
            case 5:
                tmp='1'+tmp;
                break;
            case 6:
                tmp='6'+tmp;
                break;
            case 7:
                tmp='5'+tmp;
                break;
            case 8:
                tmp='0'+tmp;
                break;
            case 9:
                tmp='3'+tmp;
                break;
        }
        n /= 10;
    }
    return tmp;
}

int main() {
    vector<pair<string,int>> V;
    int M, N;
    cin>>M>>N;

    for(int i=M; i<=N; i++)
        V.push_back(make_pair(toDictionaryOrder(i), i));

    sort(V.begin(), V.end());

    int count=0;
    for(auto i:V) {
        count++;
        cout<<i.second<<"("<<i.first<<") ";
        if(count%10==0) cout<<endl;
    }
}