// 24.01.27 SAT
// JooYoung Kim
// https://school.programmers.co.kr/learn/courses/30/lessons/49995

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> cookie) {
    int answer = 0;
    int size = cookie.size();

    for(int i=1; i<size; i++) {
        int b1_idx=i-1, b2_idx=i;
        int bro1=cookie[b1_idx], bro2=cookie[b2_idx];

        while(1) {
            cout<<"bro1"<<bro1<<"bro2"<<bro2<<endl;
            // cout<<cookie[b1_idx]<<" "<<cookie[b2_idx]<<endl;
            if(bro1 > bro2) {
                b2_idx++;
                if(b2_idx >= size) break;
                bro2 += cookie[b2_idx];
            } else if(bro1 < bro2) {
                b1_idx--;
                if(b1_idx < 0) break;
                bro1 += cookie[b1_idx];
            } else if(bro1 > answer) {      // bro1==bro2
                answer = bro1;
                cout<<"asw"<<answer<<endl;
                
                b1_idx--; b2_idx++;
                if(b1_idx < 0 || b2_idx >= size) break;
                bro1 += cookie[b1_idx];
                bro2 += cookie[b2_idx];
            }
        }
        cout<<endl;
    }
    return answer;
}

int main() {
    cout<<solution({1,1,2,3});
}