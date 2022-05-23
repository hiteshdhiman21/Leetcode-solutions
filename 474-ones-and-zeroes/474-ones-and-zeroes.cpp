class Solution {
public:  
    
    pair<int,int> count(string& s){
        int czs = 0, cos = 0;
        for(auto &ch:s){
            czs += ch=='0';
            cos += ch == '1';
        }
        return {czs, cos};
    }
    
    int findMaxForm(vector<string>& strs, int tzr, int tor) {
        //This is a Knapsack-DP problem 
        //tzr+tor = total zeros and ones corresponds to total weight
        //no. of strings in subset = total value
        
        vector<vector<int>> dp(tzr+1, vector<int>(tor+1, 0));
        
        for(int i=strs.size()-1; i>=0; i--){
            for(int cz = tzr; cz >= 0; cz--){
                for(int co = tor; co >= 0; co--){
                    //if(cz-1 >= 0) dp[cz][co] = max(dp[cz][co], dp[cz-1][co]);
                    //if(co-1 >= 0) dp[cz][co] = max(dp[cz][co], dp[cz][co-1]);
                    
                    pair<int,int> czos = count(strs[i]);
                    int czs = czos.first;
                    int cos = czos.second;
                    
                    if(cz-czs >= 0 && co-cos >= 0){
                        dp[cz][co] = max(dp[cz][co], dp[cz-czs][co-cos]+1);
                    } 
                }
            }
        }
        
        return dp[tzr][tor];
        
    }
};