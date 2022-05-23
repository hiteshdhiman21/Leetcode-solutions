class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        //Intuition: Storing only those elements in dq which are in the current window and That too in decreasing fashion. so max of window will be at dq.front()
        
        //Step-1. Travelling through the whole array.
        //Step-2. At each index, first remove out of window elements from front. And then insert the cur element such that the elements in dq are in decreasing order. Remove all the elements smaller than the current element and then insert the current element. 
        //Reason: smaller elements inserted before the current element does not matter for this and other future windows.(As in all the future windows those smaller elements present, this element also present)
        deque<int> dq;
        int n = arr.size();
        
        vector<int> ans;
        
        for(int i =0; i<n; i++){
            if(dq.front() == i-k) dq.pop_front();
            
            while(!dq.empty() && arr[dq.back()]<=arr[i]){
                dq.pop_back();
            }
            
            dq.push_back(i);
            
            if(i>=k-1){
                ans.push_back(arr[dq.front()]);
            }           
        }
        
        return ans;      
    }
    //T - O(n)
    //S - O(n)

    
};