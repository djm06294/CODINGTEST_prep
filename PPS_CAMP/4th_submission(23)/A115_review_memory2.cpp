// 문제: balloon이 몇번 만들어질 수 있는지 세기.

class Solution {
public:
    int maxNumberOfBalloons(const string &text)
    {
        vector<int> ballon_count(26, 0);
        vector<int> text_count(26, 0);
        string ballon = "balloon";
        for (char c : ballon)
        {
            ballon_count[c - 'a']++;
        }

        for (char c : text)
        {
            text_count[c - 'a']++;
        }

        int res = INT_MAX;
        for (int i = 0; i < 26; ++i)
        {
            if (ballon_count[i] > 0)
            {
                int perfect_size = ballon_count[i];
                int found_size = text_count[i];
                res = min(res, found_size / perfect_size);
            }
        }

        return res;
    }
};