// 24.01.27 SAT
// JooYoung Kim
// https://leetcode.com/problems/baseball-game/description/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores;
        int tmp1, tmp2;

        for(auto& op:operations) {
            switch(op[0]) {
                case '+':
                    tmp1 = scores.back();
                    scores.pop_back();
                    tmp2 = scores.back();
                    scores.push_back(tmp1);
                    scores.push_back(tmp1+tmp2);
                    break;
                case 'D':
                    scores.push_back(2*scores.back());
                    break;
                case 'C':
                    scores.pop_back();
                    break;
                default:
                    scores.push_back(str2int(op));  // stoi(op)로 바꾸면 훨 빨라지넹,,
            }
        }

        int sum = 0;
        for(auto& i:scores) sum += i;
        return sum;
    }

    int str2int(string str) {
        int len = str.length();
        int digit = 0;
        int num = 0;
        
        for(int i=len-1; i>0; i--) {
            num += (str[i] - '0') * pow(10,digit++);
        }
        
        if(str[0] == '-')
            num *= -1;
        else
            num += (str[0] - '0') * pow(10,digit++);

        return num;
    }
};