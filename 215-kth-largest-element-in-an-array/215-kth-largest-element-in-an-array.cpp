class Solution {
public:
    /*int findKthLargest(vector<int>& nums, int k) {
        //Step-1. Maintain a min heap so that we can remove the minimum element easily to get a heap of k largest elements.
        //Step-2. Iterate over nums array & While min heap size < k, just push the element into the min heap.
        //Step-3. If min heap size == k and also min heap's min element < x, remove min element and insert x into the heap.
        //Step-4. At last min heap will be of  k size. Just return the minimum of those largest k elements.
        priority_queue<int, vector<int>, greater<int>> mn_heap;
        for(int x: nums){
            if(mn_heap.size() < k){
                mn_heap.push(x);
            }else if(mn_heap.top() < x){
                mn_heap.pop();
                mn_heap.push(x);
            }
        }
        
        return mn_heap.top();
    }
    //T - O(nlogk)
    //S - O(k)*/
    
    int partition(vector<int>& nums, int left, int right){
        int l = left+1, r = right;
        while(l<=r){
            if(nums[l] <= nums[left]) l++;
            else if(nums[r] >= nums[left]) r--;
            else swap(nums[l++], nums[r--]);
        }
        
        swap(nums[l-1], nums[left]);
        return l-1;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size()-1;
        //kth largest would be at index nums.size()-k in sorted array
        int kthInd = nums.size()-k;
        
        while(true){
            int idx = partition(nums, left, right);
            
            if(idx < kthInd){
                left = idx+1;
            }else if(idx > kthInd){
                right = idx-1;
            }else{
                return nums[idx];
            }      
        }
        return -1;
    }
};