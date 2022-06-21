class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      /*Approach: similar to 3 sum problem*/
        sort(nums.begin(), nums.end());
        int closestSum = nums[0]+nums[1]+nums[2];
        for(int i = 0; i<nums.size(); i++){
            int s = i+1;
            int e = nums.size()-1;
            
            while(s<e){
                int threeSum = nums[i]+nums[s]+nums[e];
                if(threeSum <= target){
                    s++;
                }else{
                    e--;
                }
                
                if(abs(threeSum-target) < abs(closestSum-target))
                        closestSum = threeSum;
            }
        }
        
        return closestSum;
    }
    //T - O(n^2 + nlogn)
    //S - O(1)
};