// 문제: unit 개수가 다른 box type들을 트럭에 채워서 unit 개수 최대로 만들기.

// 앞서 본 다른 코드랑 비슷하다. for문에서 :를 사용해서 자동으로 iterate 하게 해줬다는것 말고는...? 그런데 메모리용량에서 차이가 난다니 신기하다. 또 :를 사용하지 않았다고 해서 속도가 더 빠른 것도 신기하다.
// ':'의 이름을 찾아보자. 범위기반 for문이라고 한다. (range-based for statement)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b){return a[1] > b[1];});
        int ans = 0;
        for(vector<int>& vec: boxTypes){
            int curr_num = min(truckSize, vec[0]);
            ans += curr_num*vec[1];
            truckSize -= curr_num;
            if(truckSize == 0) break;
        }
        return ans;
    }
};