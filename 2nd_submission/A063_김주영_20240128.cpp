// 24.01.28 SUN
// JooYoung Kim
// https://leetcode.com/problems/add-binary/description/

// too slow.. 다시해봐

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string answer = "";
        int len_a = a.length()-1;
        int len_b = b.length()-1;
        bool overflow = false;

        while(len_a!=len_b) {
            if(len_a>len_b) {
                b.insert(0, "0");
                len_b++;
            } else {
                a.insert(0, "0");
                len_a++;
            }
        }

        cout<<a<<" "<<b<<endl;

        for(int i=len_a; i>=0; i--) {
            if(a[i]==b[i]) {
                overflow ? answer='1'+answer : answer='0'+answer;

                if(a[i]=='0') overflow = false;
                else overflow = true;
            } else {
                overflow ? answer='0'+answer : answer='1'+answer;

                if(!overflow) overflow = false;
                else overflow = true;
            }

        }
        return overflow ? '1'+answer : answer;
    }
};

int main() {
    Solution s;
    cout<<s.addBinary("1010","1011");
}