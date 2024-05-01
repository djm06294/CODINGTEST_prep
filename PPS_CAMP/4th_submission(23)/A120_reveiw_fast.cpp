// 문제: 두 string을 구성하는 알파벳 중 동일하지 않은 하나의 알파벳 구하기.

// string s의 모든 알파벳을 알파벳 행렬에 저장하고 string t의 알파벳들도 확인한 후 동일하지 않은 알파벳을 리턴한다.
// 내 코드랑 거의 동일하다. 그냥 처음 cin, cout 속도를 줄여줘서 빠른듯 하다.

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