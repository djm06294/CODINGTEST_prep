// 문제: 연속되는 숫자 없애기.

// l과 r이 행렬의 앞에서부터 iterate 하는데 r이 l의 뒷칸에서 시작한다. 둘의 원소가 중복인 경우에 l은 가만히 있고 r이 앞으로 가면서 서로 다른 원소가 있을 때까지 간다. 다른 원소를 찾으면 l도 이동하며 그 원소를 저장해준다.
// 중복을 발견할 때마다 모든 원소를 옮길 필요 없어서 깔끔하고 빠른 코드같다! 

// 앞에 있는 8줄~13줄은 어떻게 작동하는건지 모르겠다. 속에 있는 내용은 cin과 cout을 빠르게 작동하도록 해주는 것 같은데, 이게 어디에서 불리는거지?

#include <iostream>
#include <vector>
using namespace std;

static int _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        const int n = nums.size();

        int l = 0;
        int r = 1;

        for (; r < n; r++)
        {
            if (nums[l] != nums[r])
            {
                l++;
                if (l != r)
                    nums[l] = nums[r];
            }
        }

        return l + 1;
    }
};