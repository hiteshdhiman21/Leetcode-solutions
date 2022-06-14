class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        /*Fact: first 2 if cases show that the newInterval is not overlapping and the last shows that the newInterval is overlapping.
        Step-1. Iterate over all the intervals
        Step-2. If intervals[i][end] < newInterval[start] || newInterval is already inserted, then just insert intervals[i].
        Step-3. Else if newInterval[end] < intervals[i][start] && newInterval is not inserted, then just insert the newInterval and intervals[i].
        Step-4. Else(newInterval is not inserted and is overlapping), don't insert anything but just modify the newInterval with appropriate start and end. 
        //Modified newInterval = original newInterval + overlapping intervals
        //Note that intervals which overlaps with the newInterval are not inserted and they are just used to modify the newInterval such that the newInterval includes newInterval as well as all the overlapping intervals. And those intervals will already be inserted once newInterval is inserted. 
        Step-5. Finally after traversing through all the intervals if newInterval is not inserted, just insert the modified newInterval.*/
        
        
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