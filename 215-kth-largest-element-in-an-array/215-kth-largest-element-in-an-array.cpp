class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
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