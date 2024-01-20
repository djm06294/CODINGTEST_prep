// 24.01.16 TUE
// Jooyoung Kim
// https://leetcode.com/problems/add-digits/

// little slow

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int addDigits(int num) {
        int sum=num;
        while(sum/10 != 0) {
            num = sum;
            sum = 0;
            while(num != 0) {
                sum += num%10;
                num = num/10;
            }
            cout<<sum<<endl;
        }
        return sum;
    }
};

int main() {
    Solution S;
    S.addDigits(38);
}