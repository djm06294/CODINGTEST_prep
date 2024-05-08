// 24.04.24 WED => 24.05.05 SUN
// JooYoung Kim
// "햄버거 다이어트"
// https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=3&contestProbId=AWT-lPB6dHUDFAVT&categoryId=AWT-lPB6dHUDFAVT&categoryType=CODE&problemTitle=&orderBy=RECOMMEND_COUNT&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=1
// 모르겠어서 정답보고 풀었음.

#include <iostream>
#include <string>
using namespace std;

int findLowCal(int taste[], int cal[], int& const maxCal, int const N) {
    int max=0, sumPoint=0, sumCal=0;

    for(int i=0; i<N; i++) {
        sumCal += cal[i];
        sumPoint += taste[i];

        if(sumCal > maxCal) {
            sumCal -= cal[i];
            sumPoint -= taste[i];
            if(sumPoint > max) max = sumPoint;
            continue;
        } else if(sumCal == maxCal) {
            if(sumPoint > max) max = sumPoint;
            continue;
        }

        for(int j=i+1; j<N; j++) {

        }
    }

}
// cal 높은 순으로 정렬하고 모든 경우 다 더해보는게 나을려나?

int main() {
    int T;
    cin>>T;

    for(int t=1; t<=T; t++) {
        int N, L;
        cin>>N>>L;

        int* taste = new int[N];
        int* cal = new int[N];

        for(int i=0; i<N; i++) {
            cin>>taste[i]>>cal[i];
        }
    }
}