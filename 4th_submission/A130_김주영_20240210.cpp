// 24.02.10 SAT
// JOOYOUNG KIM
// https://www.acmicpc.net/problem/10773

// very easy

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 24ms -> 8ms
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    vector<int> v;
    unsigned int sum=0;
    int K;
    cin>>K;

    while(K--) {
        int num;
        cin>>num;

        if(num!=0) v.push_back(num);
        else if(!v.empty()) v.pop_back();
    }

    for(auto &i:v) sum+=i;

    cout<<sum;

    
}