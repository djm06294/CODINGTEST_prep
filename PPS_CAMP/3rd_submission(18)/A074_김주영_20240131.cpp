// 24.01.31 TUE
// JooYoung Kim
// https://leetcode.com/problems/valid-palindrome/description/

// litte slow & large

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string ans = "";

        for(auto c:s) {
            c = tolower(c);

            if(c>='a' && c<='z') 
                ans += c;
            if(c>='0' && c<='9')
                ans += c;
            
        }

        int i=0, j=ans.length()-1;

        while(i<j) {
            if(ans[i] != ans[j]) return false;
            i++; j--;
        }

        return true;        
    }
};

int main() {
    Solution s;
    s.isPalindrome("0P");
}