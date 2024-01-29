// 24.01.27 SAT
// JooYoung Kim
// https://leetcode.com/problems/excel-sheet-column-title/description/

// slow 다시 or 다른 분꺼 리뷰

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string answer = "";
        while(columnNumber != 0) {
            char tmp = columnNumber%26 + 'A' -1;
            columnNumber /= 26;

            if(tmp == 'A'-1) {
                tmp = 'Z';
                columnNumber--;
            }
            answer = tmp + answer;
        }
        
        return answer;        
    }
};

// 남의 코드
// class Solution {
// public:
//     string convertToTitle(int cN) {
//         string s="";
//         while(cN){
//             s =char('A'+((--cN)%26))+s;
//             cN/=26;
//         }
//         return s;
//     }
// };