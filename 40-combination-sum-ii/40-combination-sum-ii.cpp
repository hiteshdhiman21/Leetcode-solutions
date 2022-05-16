class Solution {
public:
    
    void solve(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& ds, int sum, int index){
        if(index == candidates.size() || sum == target || sum>target){
            if(sum == target){
                ans.push_back(ds);
            }
            
            return;
        }
        
        for(int i=index; i<candidates.size(); i++){
            if(i == index || candidates[i] != candidates[i-1]){
                ds.push_back(candidates[i]);
                solve(candidates, target, ans, ds, sum+candidates[i], i+1);
                ds.pop_back();
            }
        }
    
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> ds;
        
        solve(candidates, target, ans, ds, 0, 0);
        
        return ans;
        
    }
};