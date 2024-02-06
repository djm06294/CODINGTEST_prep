class Solution {
public:
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        int sum1=0,sum2=0;
        for(int i=0;i<a.size();i++)
            sum1+=a[i];
        for(int i=0;i<b.size();i++)
            sum2+=b[i];
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(int i=0;i<a.size();i++)
            if(binary_search(b.begin(),b.end(),(sum2-sum1)/2+a[i]))
                return {a[i],(sum2-sum1)/2+a[i]};
        return {-1,-1};
    }
};