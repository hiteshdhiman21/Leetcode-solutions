class KthLargest {
private:
    //Heap to store k largest elements.
    priority_queue<int, vector<int>, greater<int>> mn_heap;
    int k;
    
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int x:nums) add(x);
    }
    
    int add(int val) {
        //Assumption: Mn_heap will only store k largest elements of all the elements.
        //Step-1. If there are less than k elements. just push the element into the heap.
        //Step-2. Else if(mn_heap.top() < val), This val will never be kth largest element, as now there are k or more elements larger than it already present. Else, remove the smallest element(as now it is not in k largest elements) of these k larger elements and insert val.
        //Step-3. Return the minimum of k largest element.
        
        if(mn_heap.size() < k) mn_heap.push(val);
        else{
            if(mn_heap.top() < val){
                mn_heap.pop();
                mn_heap.push(val);
            }
        }
        
        return mn_heap.top();
    }
    //T - O(nlogk)
    //S - O(k)
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */