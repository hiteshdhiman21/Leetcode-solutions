class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> res;
        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i][0] <= newInterval[0]){
                res.push_back(intervals[i]);
            }else{
                int start = newInterval[0];
                int end = newInterval[1];
                if(res.size() > 0 && res.back()[1] >= start){
                    start = res.back()[0];
                    end = max(end, res.back()[1]);
                    res.pop_back();
                }
                
                res.push_back({start, end});
                
                while(i<intervals.size()){
                    if(res.back()[1] >= intervals[i][0]){
                        res.back()[1] = max(res.back()[1], intervals[i][1]);
                    }else{
                        res.push_back(intervals[i]);
                    }
                    i++;
                }
            
            }
        }
        
        if(res.size() == 0 || res.back()[1] < newInterval[0]) res.push_back(newInterval);
        else if(res.back()[1] >= newInterval[0]) res.back()[1] = max(res.back()[1], newInterval[1]);
        return res;
    }
    //T - O(n)
    //S - O(n) Not auxillary
};