class Solution {
    vector<int> dp;
public:    
    Solution(vector<int>& w) {
        dp.resize(w.size());
        dp[0] = w[0];
        for(int i = 1; i<w.size(); i++){
            dp[i] = dp[i-1]+w[i];
        }
    }
    
    int pickIndex() {
        //Need to return index only
        int tot = dp.back();
        int val = (rand())%tot;
        int ind = upper_bound(dp.begin(), dp.end(), val)-dp.begin();
        return ind;
    }
    //T - O(logn) for each operation
    //S - O(n)
    
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */