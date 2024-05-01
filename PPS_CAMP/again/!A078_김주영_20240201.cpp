// 24.02.01 THU
// JOOYOUNG KIM
// https://school.programmers.co.kr/learn/courses/30/lessons/42747

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

    // 1 <= citations.size <= 1,000
    // 0 <= citations[i] <= 10,000
int solution(vector<int> citations) {
    int size = citations.size();
    sort(citations.begin(), citations.end(), greater<>());
    int h = citations[0];

    for(auto i:citations) cout<<i<<" ";
    cout<<endl;

    while(1) {
        for(int i=0; i<size; i++) {
            cout<<"h"<<h<<" citation[i]"<<citations[i]<<endl;
            if(citations[i] < h)  {
                if(i<h) {
                    h--;
                    break;
                } else {
                    return h;
                }
            }
            if(i==size-1) return size-1;
        }
        
    }
}

int main() {
    cout<<solution({3, 3, 6, 3, 5});
}