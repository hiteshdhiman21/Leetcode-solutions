class Solution {
public:
    
    /*int searchIn(vector<int> &nums, int start, int end, int target){
        while(start <= end){
            int mid = (start+end)/2;
            if(nums[mid] < target){
                start = mid+1;
            }else if(nums[mid] > target){
                end = mid-1;
            }else{
                return mid;
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        
         //First find index of rotation
        //Using it, we can convert the given array into two sorted arrays.
        //Use binary search separately on both the arrays.
        
        int n = nums.size();
        int indOfR = n;
        int start = 0, end = n-1;
                
        while(start <= end){
            int mid = (start+end)/2;
            if(nums[mid] >= nums[0]){
                start = mid+1;
            }else{
                indOfR = mid;
                end = mid-1;
            }
        }
        
        int ind1 = searchIn(nums, 0, indOfR-1, target);
        int ind2 = searchIn(nums, indOfR, n-1, target);
       
        
        if(ind2 != -1) return ind2;
        else return ind1;
        
        //T - 2logn             
        //S - O(1)
    }*/
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0, end = n-1;
        
        while(start <= end){
            int mid=  (start+end)/2;
            
            if(nums[mid] == target) return mid;
            else if(nums[start] <= nums[mid]){ //Is Left-side sorted
                if(nums[start] <= target && target < nums[mid]){
                    end = mid-1;
                }else{
                    start = mid+1;
                }
            }else{ //Is Right-side sorted
               if(nums[mid] < target && target <= nums[end]){
                    start = mid+1;
                }else{
                    end = mid-1;
                } 
            }
        }
         return -1;
    }
};