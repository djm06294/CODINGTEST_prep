// 24.01.12 FRI
// Jooyoung Kim
// https://leetcode.com/problems/assign-cookies/description/

// string to char array
// https://www.techiedelight.com/ko/convert-std-string-char-cpp/
// char 배열에서 숫자 뽑아내기
// https://man-25-1.tistory.com/56

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        int contentCNT = 0;

        sort(g.begin(), g.end(), greater<>());
        if(!s.empty()) sort(s.begin(), s.end(), greater<>());

        while (!s.empty() && !g.empty())
        {
            int i = s.back();
            int j = g.back();

            if (i >= j)
            {
                contentCNT++;
                g.pop_back();
            }
            s.pop_back();
        }

        return contentCNT;
    }
};


/**
int main() {
    priority_queue<int, vector<int>, greater<int>> g, s;
    int contentCNT=0;

    string str;
    cin>>str;
    int len = str.length();
    char* cStr = const_cast<char*>(str.c_str());

    bool isG = true;
    for(char* p = cStr; p < cStr+len; p++) {
        int sum=0;
        while('0' <= *p && *p <= '9') {
            sum *= 10;
            sum += *p - '0';
            p++;
        }

        if(isG && sum!=0)
            g.push(sum);
        else if(sum!=0)
            s.push(sum);

        if(*p == ']') isG = false;
    }

    while(!s.empty() && !g.empty()) {
        int i = s.top();
        int j = g.top();

        if(i >= j) {
            contentCNT++;
            g.pop();
        }
        s.pop();
    }

    cout<<contentCNT;
}
*/