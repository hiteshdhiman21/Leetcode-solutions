class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int  i = 0, j=1;
        
        int n = nums.size();
        
        while(j<n){
            if(nums[j] == nums[i]) j++;
            else nums[++i] = nums[j];
            //cout << i << " " << j << endl;
        }
        
        return i+1;
    }
};