// 24.01.15 MON
// Jooyoung Kim
// https://leetcode.com/problems/count-primes/description/

// 시간복잡도 O(Nlog(logN)) 에라토스테네스의 체 알고리즘 사용함
// https://khu98.tistory.com/227

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isPrime(int k) {
        int sqrtK = sqrt(k);
        for(int i=2; i<=sqrtK; i++) {
            if(k%i==0) return false;
        }
        return true;
    }

    int countPrimes(int n) {
        bool* isP = new bool[n];
        int count = 0;
        int sqrtN = sqrt(n);

        for(int i=0; i<n; i++) isP[i] = true;

        for(int i=2; i<n; i++) {
            if(isP[i] && i>sqrtN) count++;
            else if(isP[i] && isPrime(i)) {
                count++;
                for(int j=i; j<n; j+=i) {
                    isP[j]=false;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution S;
    cout<<S.countPrimes(5000000);
}