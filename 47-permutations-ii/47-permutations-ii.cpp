class Solution {
public:
    
    void solve(unordered_map<int, int>& freq, vector<int> &ds, vector<vector<int>> &ans, int ind ,int n){
        if(ind == n){
            ans.push_back(ds);
            return;
        }
        
        
        for(auto [x, f]: freq){
            
            if(f==0) continue;
            
            ds.push_back(x);
            freq[x]--;
            
            solve(freq, ds, ans, ind+1, n);
            
            ds.pop_back();
            freq[x]++;
        }
    }
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        unordered_map<int, int> freq;
        for(int x: nums)
            freq[x]++;
        
        vector<vector<int>> ans; 
        vector<int> ds;
        solve(freq, ds, ans, 0, nums.size());
        return ans;
        
        //T - O(nPk)  //n!/(n-k)! 
        //S - O(3n) for hash table, ds, recursion stack.
    }
};