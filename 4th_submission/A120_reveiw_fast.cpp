class Solution {
public:
    char findTheDifference(string s, string t) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = s.length();
        if(n==0) return t[0];

        int mpp[26];
        for(int i=0;i<n;++i){
            ++mpp[s[i]-'a'];
        }
        for(int i=0;i<n+1;++i){
            if(mpp[t[i]-'a']-1 < 0){
                return t[i];
            }
            --mpp[t[i]-'a'];
        }
        return 'a';
    }
};