// 24.01.31 TUE
// JooYoung Kim
// https://school.programmers.co.kr/learn/courses/30/lessons/42746

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string s1, string s2) {
    if(s1+s2 > s2+s1) return true;
    else return false;
    //바보야
    // int len1 = s1.length(), len2 = s2.length();
    // int min;
    // int i;

    // if(len1 == len2) return s1>s2;

    // if(len1<len2) {
    //     min=len1;
    //     if(s1 != s2.substr(0,min)) 
    //         return s1>s2;
    //     if(s2[min]>s2[0]) return false;
    //     else return true;       
        
    // } else {
    //     min=len2;
    //     if(s1.substr(0,min) != s2) 
    //         return s1>s2;
    //     if(s1[min]>s1[0]) return true;
    //     else return false;        
    // }
}

string solution(vector<int> numbers) {
    vector<string> numstrs;
    string answer = "";
    int max = 0;

    for(auto n:numbers) {
        numstrs.push_back(to_string(n));
    }

    sort(numstrs.begin(), numstrs.end(), compare);
    for(auto s:numstrs) {
        cout<<s<<endl;
        answer += s;
    }

    if(answer[0]=='0') return "0";

    return answer;
}

int main() {
    solution({3, 30, 34, 5, 9});
}


// 이해못한 코드
/*

#include <string>
#include <vector>
#include <sstream>

using namespace std;

int four(int n) {
    if (n > 999)
        return n;
    else if (n > 99)
        return n * 10 + n / 100;
    else if (n > 9)
        return n * 101;
    else if (n > 0)
        return n * 1111;
    else
        return 0;
}
string solution(vector<int> numbers) {
    string answer = "";
    int zero = 0;
    for (int n : numbers)
        if (!n) ++zero;
    if (zero == numbers.size())
        return "0";

    for (int i = 1; i < numbers.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (four(numbers[i]) > four(numbers[j])) 
                swap(numbers[i], numbers[j]);
        }
    }
    for (int n : numbers) {
        stringstream s;
        s << n;
        string c = s.str();
        answer += c;
    }
    return answer;
}
*/