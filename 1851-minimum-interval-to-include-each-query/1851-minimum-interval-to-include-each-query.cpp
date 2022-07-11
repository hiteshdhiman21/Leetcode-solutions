class Solution {
public:
    
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
      /*Approach: Offline queries. MinHeap
        Step-1. sort queries by coordinate and intervals by left coordinate. Alos store original index of queries
        Step-2. Iterate over queries and for each query insert into minHeap all the intervals having left <= qWithInd[0] in order {intervalSize, intervalRight}. To consider all possible intervals including it.
        Step-3. Then from minHeap. Remove only those intervals whose right < qWithInd[0] and which are smaller than the smallest intervals including the qWithInd[0]. Because larger intervals having right < qWithInd[0] will not interfere in the current query ans.
        Step-4. Finally return the res vector*/
        int n = intervals.size(), q = queries.size();
        
        vector<vector<int>> qWithInd;
        for(int i=0; i<q; i++)
            qWithInd.push_back({queries[i], i});
        
        sort(qWithInd.begin(), qWithInd.end()); 
        sort(intervals.begin(), intervals.end()); //Sorting according to left[i]
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        
        
        int j = 0;
        vector<int> res(q);
        for(int i=0; i<q; i++){
            while(j<n && intervals[j][0] <= qWithInd[i][0]){
                minHeap.push({intervals[j][1]-intervals[j][0]+1, intervals[j][1]});
                j++;
            }
            
            while(!minHeap.empty() && minHeap.top().second < qWithInd[i][0]){
                minHeap.pop();
            }
            
            if(minHeap.size()) res[qWithInd[i][1]] = minHeap.top().first;
            else res[qWithInd[i][1]] = -1;
        }
        
        return res;
    }
    //T - O(nlogn + qlogq + n + q)
    //S - O(q+n)
    
};