// 메모리 차지 덜 하는 코드
#include <iostream>
#include <string>
using namespace std;

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