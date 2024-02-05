// 문제: 과반수 개수 이상을 차지하는 한개의 수를 구하라
// linear time이라는건 한번만 iterate 하는 것, o 1 space는 다른 저장공간 복사 없는 것을 말한다.

// 이게 되는게 신기하다.
// 결국 마지막 ans에 남아있는 애가 정답이라고 어떻게 확신할 수 있었던건지 알고리즘의 원리가 따로 있는 것 같다.
// 추측해 본다면, ans가 될 애보다 ans가 안될 애들이 적을 것이기 때문에 결국 ans의 count가 남는다??

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //linear time, o 1 space
        int ans=0;
        int cnt=0;
        for(int num:nums){
            if(cnt==0) ans=num;
            
            if(num==ans) cnt++;
            else cnt--;
        }
        return ans;
    }
};