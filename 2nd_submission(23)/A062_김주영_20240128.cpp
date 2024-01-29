// 24.01.28 SUN
// JooYoung Kim
// https://school.programmers.co.kr/learn/courses/30/lessons/12901

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solution(int a, int b) {
    string weekdays[] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
    int days[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int seed = 5;

    for(int i=0; i<a-1; i++) 
        seed += days[i];

    seed += b-1;

    return weekdays[seed%7];
}

int main() {
    cout<<solution(5,24);
}