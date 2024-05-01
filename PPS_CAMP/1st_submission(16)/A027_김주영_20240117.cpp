// 24.01.17 FRI
// JooYoung Kim
// https://school.programmers.co.kr/learn/courses/30/lessons/42883

// 몇번 갈아엎고 다시 짬 ㅜ 좀더 읽기 쉬운 알고리즘으로 짜보고 싶음.

#include <iostream>

#include <string>
#include <vector>

using namespace std;

int findMax(string str) {
    int maxIdx = 0;
    char maxChar = '0'-1;
    for(int i=0; i<str.length(); i++) {
        if(str[i]>maxChar) {
            maxChar = str[i];
            maxIdx = i;
        }
    }
    return maxIdx;
}

string solution(string number, int k) {
    string answer = "";
    int it=0;
    while(k<number.length()) {
        string tmp = number.substr(it,++k-it);
        it += findMax(tmp);
        answer += number[it];
        it++;
    }

    return answer;
}

int main() {
    cout<<solution("1924",2)<<endl;
    cout<<solution("1231234",3)<<endl;
    cout<<solution("4177252841",4)<<endl;
}

