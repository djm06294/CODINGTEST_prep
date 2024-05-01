// 24.01.31 TUE
// JooYoung Kim
// https://leetcode.com/problems/fizz-buzz/description/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer;
        for(int i=1; i<=n; i++) {
            string tmp = isFizz(i)+isBuzz(i);
            
            if(tmp.length()==0) {
                answer.push_back(to_string(i));
            } else {
                answer.push_back(tmp);
            }
        }
        return answer;        
    }

    string isFizz(int n) {
        if(n%3==0) return "Fizz";
        return "";
    }
    string isBuzz(int n) {
        if(n%5==0) return "Buzz";
        return "";
    }
};