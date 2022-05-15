class Solution {
public:
    
    void solve(vector<int> &nums, vector<vector<int>> &ans, int ind, vector<int> ds, map<int, int>& indices){
        if(ind == nums.size()){
            ans.push_back(ds);
            return;
        }
        
        int ind2 = indices[nums[ind]]+1;
        for(int i = ind-1; i < ind2; i++){
            if(i>=ind){
                ds.push_back(nums[ind]);
                solve(nums, ans, ind2, ds, indices);
            }else{
                solve(nums, ans, ind2, ds, indices);
            }
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        map<int, int> indices;
        for(int i=0; i<nums.size(); i++){
            indices[nums[i]] = i;
        }
        vector<int> ds;
        solve(nums, ans, 0, ds, indices);
        return ans;
    }
};