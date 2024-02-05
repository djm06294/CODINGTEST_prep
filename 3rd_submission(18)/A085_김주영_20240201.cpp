// 24.02.01 THU
// JOOYOUNG KIM
// https://www.acmicpc.net/problem/1431

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compareGuitar(string a, string b) {
    int lenA = a.length(), lenB = b.length();
    if(lenA != lenB) 
        return lenA < lenB;

    int sumA=0, sumB=0;
    for(int i=0; i<lenA; i++) {
        if(a[i]>='0' && a[i]<='9') sumA += a[i] - '0';
        if(b[i]>='0' && b[i]<='9') sumB += b[i] - '0';
    }

    if(sumA != sumB) 
        return sumA < sumB;

    else return a < b;
}

int main() {
    vector<string> V;
    int N;      // <=50
    cin>>N;

    while(N--) {
        string s;
        cin>>s;
        V.push_back(s);
    }

    sort(V.begin(), V.end(), compareGuitar);

    for(auto s:V) 
        cout<<s<<endl;
}