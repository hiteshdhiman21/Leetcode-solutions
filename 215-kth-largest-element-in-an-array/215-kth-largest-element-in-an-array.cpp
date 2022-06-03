class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
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
    //S - O(k)
};