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
        if(mx_heap.size() == mn_heap.size()){
            if(mx_heap.size() == 0 || mn_heap.top() >= num)
                //[[1, 4] [7, 10]] to [[1, 4, 6] [7, 10]]           Inserting 6
                //[[1, 4] [7, 10]] to [[1, 2, 4] [7, 10]]           Inserting 2
                //[[1, 4] [7, 10]] to [[1, 4, 7] [7, 10]]           Inserting 7
                mx_heap.push(num);
            else{
                //[[1, 4] [7, 10]] to [[1, 4, 7] [9, 10]]           Inserting 9
                //[[1, 4] [7, 10]] to [[1, 4, 7] [10, 11]]          Inserting 11
                mx_heap.push(mn_heap.top());
                mn_heap.pop();
                mn_heap.push(num); 
            }
        }else{
            if(num < mx_heap.top()){
                //[[1, 3, 5] [7, 10]] to [[1, 3, 4] [5, 7, 10]]     Inserting 4
                //[[1, 3, 5] [7, 10]] to [[1, 2, 3] [5, 7, 10]]     Inserting 2
                mn_heap.push(mx_heap.top());
                mx_heap.pop();
                mx_heap.push(num);
            }else{
                //[[1, 3, 5] [7, 10]] to [[1, 3, 5] [5, 7, 10]]     Inserting 5
                //[[1, 3, 5] [7, 10]] to [[1, 3, 5] [7, 10, 20]]    Inserting 20
                mn_heap.push(num);
            }
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