class Solution {
public:
    
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
      /*K closest element will be next to each other in the original array
        Step-1. Find starting point of K closest elements using binary search
        Step-2. Copy k elements from that point into the res array and return it*/
        int n = nums.size();
        int start = 0, end = nums.size()-k;
        int toBeginFrom = -1;
        
        if(start == end)
            toBeginFrom = start;
        
        while(start < end){
            int mid = start+(end-start)/2;
            if(mid+k < n && x-nums[mid] > nums[mid+k]-x){ //mid+1 is better option than mid
                toBeginFrom = mid+1;
                start = mid+1;
            }else{ //mid is better option than mid+1
                toBeginFrom = mid;
                end = mid;
            }
        }
        
        vector<int> res(nums.begin()+toBeginFrom, nums.begin()+toBeginFrom+k);
        return res;
    }
    
    /*vector<int> findClosestElements(vector<int>& nums, int k, int x) {
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
    //T - O(k+nlogn)
    //S - O(k)*/
};