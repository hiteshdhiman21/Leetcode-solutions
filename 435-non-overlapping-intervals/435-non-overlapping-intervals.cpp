class Solution {
public:
    static bool cmp(vector<int>& i1, vector<int>& i2){
        return i1[1] < i2[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int cnt = 0;
        sort(intervals.begin(), intervals.end(), cmp);
        
        int lastInd = 0;
        for(int i=1; i<intervals.size(); i++){
            if(intervals[lastInd][1] > intervals[i][0])
                cnt++;
            else
                lastInd = i;
        }
        
        return cnt;        
    }
    //T - O(nlogn)
    //S - O(1)
};