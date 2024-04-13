// 24.02.07 WED
// JOOYOUNG KIM
// https://www.acmicpc.net/problem/10834

// 왜 int가 아닌 float로 하면 틀리는건지 모르겠다.

#include <iostream>
using namespace std;

int main() {
    int BeltNum;
    cin>>BeltNum;

    int answer = 1.; // 분당 회전율
    bool dir = 0;   // 시계방향을 fasle, 반시계방향을 true라 하자.

    while (BeltNum--) {
        int a, b;
        bool beltType;
        cin>>a>>b>>beltType;

        answer = (answer/a) * b;
        if(beltType) dir=!dir;
    }

    cout<<dir<<" "<< answer;    
}