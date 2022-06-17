class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> res;
        int closestIndex = -1;
        int smallestDiff = INT_MAX;
        
        int start = 0, end = n-1;
        while(start <= end){
            int mid = start+(end-start)/2;
            
            if(x < nums[mid]){
                if(smallestDiff > abs(x-nums[mid])){
                    smallestDiff = abs(x-nums[mid]);
                    closestIndex = mid;
                }
                end = mid-1;
            }else if(x > nums[mid]){
                if(smallestDiff > abs(x-nums[mid])){
                    smallestDiff = abs(x-nums[mid]);
                    closestIndex = mid;
                }
                start = mid+1;
            }else{
                closestIndex = mid;
                break;
            }
        }
        
        start= closestIndex, end = closestIndex;
        while(end-start+1 < k){
            if(start-1 >= 0 && (end+1 == n || abs(nums[start-1]-x) <= abs(nums[end+1]-x)))
                start--;
            else
                end++;
        }
        
        
        for(int i = start; i<=end; i++){
            res.push_back(nums[i]);
        }
        
        return res;
    }
};