// 문제: unit 개수가 다른 box type들을 트럭에 채워서 unit 개수 최대로 만들기.

// 20줄의 min 함수를 사용해서, box의 개수와 트럭의 남은 공간을 비교하고 그 중 작은 애만큼 한번에 트럭에 실어주도록 설계했다.

// 15줄에 sort 함수를 부르면서 내장함수(?) 정의한 것이 신기하다. 더 알아보고 싶다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n=boxTypes.size();
        sort(boxTypes.begin(),boxTypes.end(),[](const vector<int>&a,const vector<int>&b){
            return a[1]>b[1];
        });

        int val=0;
        for(int i=0;i<n;i++)
        {
            int x=min(boxTypes[i][0],truckSize);
            val+=x*boxTypes[i][1];
            truckSize-=x;
            if(!truckSize)break;
            cout<<val<<endl;
        }
        return val;
    }
};