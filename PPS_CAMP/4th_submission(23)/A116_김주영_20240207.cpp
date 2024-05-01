// 24.02.07 WED
// JOOYOUNG KIM
// https://leetcode.com/problems/day-of-the-week/description/

#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    bool isLeapYear(int year) {
        if(year%400==0) return true;
        if(year%100==0) return false;
        if(year%4==0) return true;
        return false;
    }

    string dayOfTheWeek(int day, int month, int year) {
        string day_names[] = {"Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday"};

        int sum_days = 0;

        for(int i=1971; i<year; i++) {
            sum_days += 365;
            if(isLeapYear(i)) sum_days++;
        }

        for(int i=1; i<month; i++) {
            if(i==2) 
                sum_days += isLeapYear(year) ? 29 : 28;
            else if(i==4 || i==6 || i==9 || i==11)
                sum_days += 30;
            else
                sum_days += 31;
        }

        sum_days += day;

        return day_names[sum_days%7];        
    }
};

int main() {
    Solution s;
    cout<<s.dayOfTheWeek(1,1,1971)<<endl;
    cout<<s.dayOfTheWeek(31,8,2019)<<endl;
    cout<<s.dayOfTheWeek(1,1,1971)<<endl;
}