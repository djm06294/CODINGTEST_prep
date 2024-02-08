// 내 옛날 코드. 시간이나 메모리 둘다 똑같음
#include <iostream>
using namespace std;
int main() {
    int t,a,b,mul=1;
    cin>>t;
    for(int i=0; i<t; i++) {
        mul=1;
        cin>>a>>b;
        while((a*mul)%b!=0) mul++;
        cout<<a*mul<<"\n";
    }
}