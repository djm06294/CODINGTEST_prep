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