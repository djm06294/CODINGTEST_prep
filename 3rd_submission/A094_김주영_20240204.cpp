// 24.02.04 SUN
// JOOYOUNG KIM
// https://leetcode.com/problems/merge-sorted-array/description/

#include <iostream>
#include <string>
using namespace std;

int main() {
    int count=0;
    string str;
    cin>>str;
    int len = str.length();

    for(int i=0; i<len; i++) {
        if(str[i]>='a' && str[i]<='z') count++;

        if(str[i]=='d' && str.substr(i,3)=="dz=") i+=2;
        else if(str[i]=='l' && str[i+1]=='j') i++;
        else if(str[i]=='n' && str[i+1]=='j') i++;
    }
    
    cout<<count;
}