class MedianFinder {
private:
    priority_queue<int> mx_heap; //For storing first half 
    priority_queue<int, vector<int>, greater<int>> mn_heap; //For storing next half
    
    
    
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mx_heap.size() == mn_heap.size()){
            if(mx_heap.size() == 0 || mn_heap.top() >= num)
                mx_heap.push(num);
            else{
                mx_heap.push(mn_heap.top());
                mn_heap.pop();
                mn_heap.push(num); 
            }
        }else{
            if(num < mx_heap.top()){
                mn_heap.push(mx_heap.top());
                mx_heap.pop();
                mx_heap.push(num);
            }else{
                mn_heap.push(num);
            }
        }
    }
    
    double findMedian() {
        int total_elements = mx_heap.size()+mn_heap.size();
        if((total_elements)%2 == 0) return (mx_heap.top()+mn_heap.top())/2.0;
        else return mx_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */