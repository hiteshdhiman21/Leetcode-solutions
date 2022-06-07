class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
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