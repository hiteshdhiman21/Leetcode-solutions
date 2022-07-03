class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(int &x: stones) maxHeap.push(x);
        
        while(maxHeap.size() > 1){
            int fmx = maxHeap.top(); maxHeap.pop();
            int smx = maxHeap.top(); maxHeap.pop();
            
            if(fmx != smx)
                maxHeap.push(fmx-smx);
        }
        
        int res = 0;
        if(maxHeap.size() == 1)
            res = maxHeap.top();
        
        return res;
    }
    //T - O(nlogn)
    //S - O(n)
    
};