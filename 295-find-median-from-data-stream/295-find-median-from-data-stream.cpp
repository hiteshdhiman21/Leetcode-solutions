class MedianFinder {
private:
    priority_queue<int> mx_heap; //For storing first half 
    priority_queue<int, vector<int>, greater<int>> mn_heap; //For storing next half
    
    //Maintaining both mn and mx heap such that the following properties are always followed:
    //Even elements: mx_heap store first half and mn_heap store second half of sorted elements
    //Odd elements: mx_heap store first half + one more and mn_heap store second half of sorted elements.
    
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if(mx_heap.size() == 0 || num < mx_heap.top()) mx_heap.push(num);
        else mn_heap.push(num);
        
        //Now below 2 if statements are just maintaining order and size of both the heaps
        if(mx_heap.size() > mn_heap.size()+1){
            mn_heap.push(mx_heap.top());
            mx_heap.pop();
        }else if(mx_heap.size() < mn_heap.size()){
            mx_heap.push(mn_heap.top());
            mn_heap.pop();
        }
        
    }
    
    double findMedian() {
        //Even no. of elements
        if((mx_heap.size()+mn_heap.size())%2 == 0) return (mx_heap.top()+mn_heap.top())/2.0;
        //Odd no. of elements
        else return mx_heap.top();
    }
    //T - nlogn,    logn for each addNum() and 1 for each findMedian()
    //S - O(n) for storing total elements
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */