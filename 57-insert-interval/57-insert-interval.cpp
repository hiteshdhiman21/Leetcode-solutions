class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> res;
        bool isInserted = false;
        for(int i = 0; i < intervals.size(); i++){
            if(newInterval[1] < intervals[i][0] && !isInserted){
                res.push_back(newInterval);
                res.push_back(intervals[i]);
                isInserted = true;
            }else if(intervals[i][1] < newInterval[0] || isInserted){
                res.push_back(intervals[i]);
            }else{
                newInterval = {min(newInterval[0], intervals[i][0]), max(intervals[i][1], newInterval[1])};
            }
        }
        
        if(!isInserted) res.push_back(newInterval);
        return res;
    }
    //T - O(n)
    //S - O(n) Not auxillary
};