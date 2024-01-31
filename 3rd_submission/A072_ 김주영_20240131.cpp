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


// 메모리 차지 덜 하는 코드
/*
class Solution {
public:
    int isleapyear(int year)
    {
        if(year%100 != 0)
        {
            if(year%4==0)
            {
                return 1;
            }
        }
        else
        {
            if(year%400==0)
            {
                return 1;
            }
        }
        return 0;
    }
    int dayOfYear(string date) {
        //"2019-01-09"
        //"0123456789"
        int day = (date[8]-'0')*10 + (date[9]-'0');
        int mon = (date[5]-'0')*10 + (date[6]-'0');
        int year= (date[0]-'0')*1000 + (date[1]-'0')*100 +(date[2]-'0')*10 +(date[3]-'0');
        int ans=day;
        for(int i=1; i<mon;i++)
        {
            if(i==4 || i==6 || i==9 || i==11)
            {
                ans += 30;
            }
            else if(i==2)
            {
                if (isleapyear(year)==1)
                {
                    ans += 29;
                }
                else
                {
                    ans +=28;
                }
            }
            else
            {
                ans +=31;
            }
        }
        return ans;
        
    }
};
*/