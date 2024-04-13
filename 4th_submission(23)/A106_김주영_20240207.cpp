// 24.02.07 WED
// JOOYOUNG KIM
// https://www.acmicpc.net/problem/3059

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin>>T;

    while(T--) {
        bool alphaExist[26] = {0};
        int sum = 0;
        string s;
        cin>>s;

        for(auto c:s)
            alphaExist[c-'A'] = 1;

        for(int i=0; i<26; i++) {
            if(alphaExist[i]==false) sum += 'A'+i;
            cout<<sum<<endl;
        }
        
        cout<<sum<<endl;
    }

}