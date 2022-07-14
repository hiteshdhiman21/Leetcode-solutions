class Solution {
public:
    
    void solve(vector<int>& nums, int ind, vector<vector<int>>& ans){
    if(ind == nums.size()){
        ans.push_back(nums);
        return;
    }
 //Maintained set so that do not set same value in ind different times.
    set<int> s;
    for(int i=ind; i<nums.size(); i++){
        if(s.count(nums[i])){
            //cout << ind << " "<<i << endl;
            continue;
        }
        
        s.insert(nums[i]);
        swap(nums[ind], nums[i]);
        solve(nums, ind+1, ans);
        swap(nums[ind], nums[i]);
        
    }
}
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> ans;        
        solve(nums, 0, ans);
        return ans;
        
        //T - O(nPk)  //n!/(n-k)! 
        //S - O(3n) for hash table, ds, recursion stack.
    }
};