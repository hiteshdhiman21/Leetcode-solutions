class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> mn_heap;
    int k;
    
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int x:nums) add(x);
    }
    
    int add(int val) {
        if(mn_heap.size() < k) mn_heap.push(val);
        else{
            if(mn_heap.top() < val){
                mn_heap.pop();
                mn_heap.push(val);
            }
        }
        
        return mn_heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */