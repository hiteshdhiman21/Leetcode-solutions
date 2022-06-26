class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        
        int points = 0;
        for(int i = n-1; i>=n-k; i--) points += cardPoints[i];
        
        int res = 0;
        
        for(int i = 0; i<=k; i++){
            res = max(res, points);
            
            if(i==k) break;
            points -= cardPoints[n-k+i];
            points += cardPoints[i];
        }
        
        return res;
    }
    //T - O(n)
    //S - O(1)
};