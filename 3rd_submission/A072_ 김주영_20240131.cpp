// 24.01.31 TUE
// JooYoung Kim
// https://leetcode.com/problems/day-of-the-year/description/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int dayOfYear(string date) {
        int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        int year = stoi(date.substr(0,4));
        int month = stoi(date.substr(5,2));
        int day = stoi(date.substr(8));
        int daynum = 0;

        for(int i=0; i<month-1; i++)
            daynum+=months[i];

        if(month>2 && isYoonYear(year)) daynum++;

        daynum+=day;
        
        return daynum;        
    }

    bool isYoonYear(int year) {
        if(year%400==0) return true;
        else if(year%100==0) return false;
        else if(year%4==0) return true;
        else return false;
    }
};