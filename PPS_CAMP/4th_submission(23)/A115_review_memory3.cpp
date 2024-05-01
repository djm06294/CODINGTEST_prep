// 문제: balloon이 몇번 만들어질 수 있는지 세기.

// balloon의 알파벳일 경우에만 원본 text에서의 알파벳 갯수를 balloon의 알파벳 갯수로 나누어서 최소값을 저장함.

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(26, 0);

        for(char ch : text) {
            freq[ch - 'a']++;
        }

        string str = "balloon";

        vector<int> b_freq(26, 0);
        for(char ch : str) {
            b_freq[ch - 'a']++;
        }

        int ans = 1e5;
        for(int i = 0; i < 26; i++) {
            if(b_freq[i] == 0) continue;
            
            ans = min(ans, freq[i] / b_freq[i]);
        }

        return ans;
    }
};