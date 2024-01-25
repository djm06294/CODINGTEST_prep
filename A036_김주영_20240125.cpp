// 24.01.25 THU
// JooYoung Kim
// https://leetcode.com/problems/self-dividing-numbers/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;

        for(int n=left; n<=right; n++) {
            int tmp = n;
            while(tmp != 0) {
                if(tmp%10 == 0) break;
                if(n%(tmp%10) != 0) break;

                tmp = tmp/10;
                if(tmp==0) result.push_back(n);
            }
        }   
        return result;     
    }
};

// n  1234
// t  123 12 1

int main(int argc, char* argv[]) {
    Solution s;
    vector<int> a = s.selfDividingNumbers(47,85);
    for(auto& i: a) cout <<i<<" ";
}