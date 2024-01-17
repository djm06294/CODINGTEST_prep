// 24.01.17 FRI
// Jooyoung Kim
// https://leetcode.com/problems/lemonade-change/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int> bills) {
        int five=0, ten=0;

        for(auto& i:bills) {
            cout<<i<<" five:"<<five<<" ten:"<<ten<<endl;
            if(i==5) {
                five++;
            } else if(i==10) {
                if(five<1) return false;
                ten++;
                five--;
            } else if(i==20) {
                if(five<1) return false;
                if(ten<1 && five<3) return false;

                if(ten>0) {
                    ten--;
                    five--;
                } else {
                    five-=3;
                }
            }
        }

        return true;        
    }
};

int main() {
    Solution s;
    cout<<s.lemonadeChange({5,5,5,10,20})<<endl;
    cout<<s.lemonadeChange({5,5,10,10,20})<<endl;
    cout<<s.lemonadeChange({5,5,10,20,5,5,5,5,5,5,5,5,5,10,5,5,20,5,20,5})<<endl;
}