class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        if (month == 1) {
            month = 13;
            year--;
        }
        if (month == 2) {
             month = 14;
            year--;
        }
        int ans,k=year%100,j=year/100;
        ans=(day+(13*(month+1)/5)+k+k/4+j/4+5*j)%7;
        switch (ans)
        {
        case 0:
            return "Saturday";
        case 1:
            return "Sunday";
        case 2:
            return "Monday";
        case 3:
            return "Tuesday";
        case 4:
            return "Wednesday";
        case 5:
            return "Thursday";
        }
        return "Friday";
    }
};