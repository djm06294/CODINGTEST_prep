// 문제: 그 날짜의 요일을 찾기

// 일요일인 오늘까지의 날과 주어진 날까지의 날을 계산해서 그 차를 가지고 요일을 알아내는 알고리즘이다.

class Solution {
public:
    int daysOfMonth[2][12] = {
        31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };
    string weekName[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    bool isleapyear(int year)
    {
        return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
    }
    int daystill1971(int year, int month, int day)
    {
        int count = 0;
        int year1 = 1970, month1 = 1, day1 = 1;
        while (year1 != year)
        {
            bool b = isleapyear(year1);
            if (b) count += 366;
            else count += 365;
            year1++;
        }
        int b = isleapyear(year1) ? 0 : 1;
        for (int i = 0; i < month - 1; i++) count += daysOfMonth[b][i];
        count += day - 1;
        return count;
    }
    string dayOfTheWeek(int day, int month, int year) {
        int days1 = daystill1971(2019, 9, 8);//today(2019,9,8) is Sunday
        int days2 = daystill1971(year, month, day);
        int days = (((days2 - days1) % 7) + 7) % 7;//Number of days off
        return weekName[days];
    }
};