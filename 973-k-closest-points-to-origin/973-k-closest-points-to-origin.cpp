class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int,int>>> pq;
        for(int i =0; i<points.size(); i++){
            int x = points[i][0], y = points[i][1];
            int dist = x*x+y*y;
            if(i<k) 
                pq.push({dist, {x, y}});
            else if(pq.top().first > dist){
                pq.pop();
                pq.push({dist, {x, y}});
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            ans.push_back({x,y});
            pq.pop();
        }
        
        return ans;
    }
};