// 24.02.10 SAT
// JOOYOUNG KIM
// https://www.acmicpc.net/problem/9095

#include <iostream>
using namespace std;

int factorial(int n) {
    int ans=1;
    
    while(n) 
        ans *= n--;
    
    return ans;
}

int main() {
    int T;
    cin>>T;

    while(T--) {
        int N, count=0;
        int three, two, one;
        cin>>N;

        for(three = N/3; three>=0; three--) {
            two = (N - 3*three) / 2;

            for(two; two>=0; two--) {
                one = N - 3*three - 2*two;
                
                count += factorial(three+two+one) / (factorial(three) * factorial(two) * factorial(one));
            }
        }
        cout<<count<<endl;
    }

}