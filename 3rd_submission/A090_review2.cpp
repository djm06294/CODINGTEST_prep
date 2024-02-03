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