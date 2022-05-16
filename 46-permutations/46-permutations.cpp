class Solution {
public:
    void solve(vector<int>& nums, int ind, vector<vector<int>>& ans){
        if(ind == nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i=ind; i<nums.size(); i++){
            swap(nums[ind], nums[i]);
            solve(nums, ind+1, ans);
            swap(nums[ind], nums[i]);
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
       
        vector<vector<int>> ans;        
        solve(nums, 0, ans);
        return ans;
        //T - O(n!*n)  //n+n(n-1)+n(n-1)(n-2)+ + + + + + + n! times traversing array from (ind to n-1). 
        //S - O(1) (Not using any data structure or mark array)
        //AS- O(n) (Just because of recursion stack)
    }
};