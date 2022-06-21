class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      /*Approach: similar to 3 sum problem*/
        sort(nums.begin(), nums.end());
        int closestSum = INT_MAX;
        for(int i = 0; i<nums.size(); i++){
            int s = i+1;
            int e = nums.size()-1;
            
            while(s<e){
                int threeSum = nums[i]+nums[s]+nums[e];
                if(threeSum <= target){
                    if(closestSum==INT_MAX || abs(threeSum-target) < abs(closestSum-target))
                        closestSum = threeSum;
                    s++;
                }else{
                    if(closestSum==INT_MAX ||abs(threeSum-target) < abs(closestSum-target))
                        closestSum = threeSum;
                    e--;
                }
            }
        }
        
        return closestSum;
    }
    //T - O(n^2 + nlogn)
    //S - O(1)
};