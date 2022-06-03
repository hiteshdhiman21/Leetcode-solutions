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
    
    int partition(vector<int>& nums, int& left, int& right){
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
        //Approach: Quick select (just like partition of quick sort)
        //partition() returns the partition index along with the max value of left half present at the partition index. All the elements at indexes nums[1...partition] < nums[partition+1 ... n]
        //If parIdx < kth value Indes, we have to call partition on (parIdx+1, right)
        //Else if parIdx > kth value index, we have to call partition on (left, parIdx-1)
        //Else parIdx == kth value index, and as the smallest parIdx+1 values are present at first [0..parIdx] and the largest of them is present at [parIdx], and we need kth[parIdxth or largest value of first k+1 values in sorted array] value of the sprted array. Return nums[parIdxth].
        int left = 0, right = nums.size()-1;
        //kth largest would be at index nums.size()-k in sorted array
        //It means we need the kth value in sorted array or largest of the first k+1 values
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
    //T - Average(n) , Worst(n^2)
    //S - O(1)
};