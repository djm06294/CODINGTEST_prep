// 문제: 연속되는 숫자 없애기.

// set은 중복이 안되므로 set에 넣어줬다가 기존의 vector에 옮겨줬다. 신박하다.

// 중복을 발견하면 나머지를 한칸씩 옮겨주는 방식보다는 빠른 것 같다.
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        for (vector<int>::iterator i = nums.begin(); i < nums.end(); i++)
        {
            s.insert(*i);
        }
        nums.clear();
        for(set<int>::iterator i=s.begin();i!=s.end();i++)
        {
            nums.push_back(*i);
        }
        return s.size();
    }
};