// 메모리 차지 덜 하는 코드
// 4,6,9,11월인 경우에는 30일을 더해주고, 2월이면 윤년인지 확인해주었다.
// 내 코드와 다른 점은 각 month의 날짜들을 따로 저장해두지 않고 그냥 if 문을 통해 무슨 월인지 계산했다는 것 정도?
// 크게 좋은 코드라는 생각이 들지는 않는다.

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int isleapyear(int year)
    {
        if(year%100 != 0)
        {
            if(year%4==0) return 1;
        }
        else
        {
            if(year%400==0)
                return 1;
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