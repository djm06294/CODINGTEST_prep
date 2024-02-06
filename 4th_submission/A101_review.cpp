class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        vector<int> answer;
        int sumAlice = 0, sumBob = 0;
        for (int i = 0; i < aliceSizes.size(); i++)
            sumAlice += aliceSizes[i];
        for (int i = 0; i < bobSizes.size(); i++) {
            sumBob += bobSizes[i];
        }
        sort(aliceSizes.begin(), aliceSizes.end());
        sort(bobSizes.begin(), bobSizes.end());
        int ai = 0, bi = 0;
        while (ai < aliceSizes.size() && bi < bobSizes.size()) {
            int b_el = bobSizes[bi], a_el = aliceSizes[ai];
            int tmp_a = sumAlice - a_el + b_el;
            int tmp_b = sumBob - b_el + a_el;
            
            if (tmp_a == tmp_b)
                return {a_el, b_el};
            else if (tmp_a < tmp_b)
                bi++;
            else
                ai++;
        }
        return answer;
    }
};