// 문제: balloon이 몇번 만들어질 수 있는지 세기.

// 코드가 짧아서 좋다. 각 알파벳으로 만들 수 있는 balloon의 갯수 중 가장 작은 것을 return 하는 것이 깔끔하다.

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int arr [26] = {0};
        for(auto x : text){
            arr[x-'a']++;
        }
        return min({arr[0],arr[1],arr[14]/2,arr[11]/2 , arr[13]});
    }
};