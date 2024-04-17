// 24.04.17 WED
// JooYoung Kim
// "증가하는 사탕 수열"
// https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=3&contestProbId=AY4XhKTKU0IDFARM&categoryId=AY4XhKTKU0IDFARM&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=1

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    int boxes[3];
    cin>>T;

    for(int t=1; t<=T; t++) {
        int eat = 0;

        for(int i=0; i<3; i++)
            cin>>boxes[i];
        
        // 마지막 box에는 최소 3개 이상
        if(boxes[2]<3) {
            cout<<"#"<<t<<" "<<-1<<"\n";
            continue;
        }

        for(int i=2; i>0; i--) {
            int sub = boxes[i] - boxes[i-1];
            
            if(sub > 0) continue;

            sub = -sub;
            boxes[i-1] -= sub+1;

            if(boxes[i-1] <= 0) {
                eat = -1;
                cout<<"#"<<t<<" "<<-1<<"\n";
                break;
            }
            
            eat += sub+1;
        }

        if(eat!=-1) cout<<"#"<<t<<" "<<eat<<"\n";

    }
}