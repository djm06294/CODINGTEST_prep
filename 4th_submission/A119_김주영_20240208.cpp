// 24.02.08 THU
// JOOYOUNG KIM
// https://leetcode.com/problems/guess-number-higher-or-lower/description/

#include <iostream>
#include <string>
using namespace std;

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guess(int num);
    
    int guessNumber(unsigned int n) {
        unsigned int st = 1, end = n+1;
        unsigned int i = n/2;
        while(1) {
            int g = guess(i);
            if(!g) return i;

            if(g==-1) {
                end = i;
                i = (st+i)/2;
            } else if(g==1) {
                st = i;
                i = (end+i)/2;
            }
        }
    }
};