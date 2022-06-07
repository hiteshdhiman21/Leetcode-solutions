class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //Step-1. First make a hashmap of each element with its frequency.
        //Step-2. Now maintain a minHeap and iterate over the hashmap. If minHeap size < k just push the {cnt, x} into the minHeap. Else check if minHeap minFreq < cnt and if true, just push the {cnt, x} into the queue.
        //Step-3. Finally just add the value part of minHeap into the ans vector.
        
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        unordered_map<int, int> freq;
        for(int x:nums) freq[x]++;
        
        for(auto __:freq){
            int x = __.first, cnt = __.second;
            if(pq.size() != k){
                pq.push({cnt, x});
            }else if(pq.top().first < cnt){
                pq.pop();
                pq.push({cnt, x});
            }
        }
        
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
    //T - O(nlogk)
    //S - O(n)
};