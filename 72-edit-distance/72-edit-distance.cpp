class Solution {
public:
    /*int minDistance(string word1, string word2) {
        if(word1.size() == 0 || word2.size()==0){
            return max(word1.size(), word2.size());
        }
        
        if(word1[0] == word2[0])
            return minDistance(word1.substr(1), word2.substr(1));
        
        int ans1 = 1+minDistance(word1.substr(1), word2);
        int ans2 = 1+minDistance(word1.substr(1), word2.substr(1));
        int ans3 = 1+minDistance(word1, word2.substr(1));
        
        return min(ans1, min(ans2, ans3));
    }
    
    int minDistance(string word1, string word2, int** ans) {
        if(word1.size() == 0 || word2.size()==0){
            return max(word1.size(), word2.size());
        }
        
        int m = word1.length();
        int n = word2.length();
        
        if(ans[m][n] != -1){
            return ans[m][n];
        }        
        
        if(word1[0] == word2[0]){
            ans[m][n] =  minDistance(word1.substr(1), word2.substr(1));
            return ans[m][n];
        }
        
        int ans1 = 1+minDistance(word1.substr(1), word2);
        int ans2 = 1+minDistance(word1.substr(1), word2.substr(1));
        int ans3 = 1+minDistance(word1, word2.substr(1));
        
        ans[m][n] = min(ans1, min(ans2, ans3));
        return ans[m][n];
    }
    
    int minDistance(string word1, string word2) {
        
        int m = word1.length();
        int n = word2.length();
        
        int **ans = new int*[m+1];
        for(int i=0; i<=m; i++){
            ans[i] = new int[n+1];
            for(int j=0; j<=n; j++){
                ans[i][j] = -1;
            }
        }
        
        return minDistance(word1, word2, ans);
    }*/
    
    int minDistance(string word1, string word2) {
    /*  Step-1. dp[i][j] denotes the min Distance if word1 starts from index i(m-1 character) and word2 starts from index j(n-j characters)
        Step-2. if word1[i] == word2[j], dp[i][j] = dp[i+1][j+1] because no need to match word1[i] and word2[j].
        Step-3. Else, three ways to match word1[i] each costs 1 operations. 
        Insertion: Insert word2[j] in word1 and Now word2[j] is matched. So find dist word1[i...m] with word2[j+1 ... n] i.e. Find dp[i][j+1].
        Deletion: Delete word1[i] and since no need to match word[i] now. So find dist word1[i+1...m] with word2[j ... n] i.e. Find dp[i+1][j].
        Replace: Replace word1[i] with word2[j]. So find dist word1[i+1...m] with word2[j+1 ... n] i.e. Find dp[i+1][j+1].
        Step-4. Finally return dp[0][0] i.e. dist between word1[0..m] and word2[0..n].
        */
        
        int m = word1.size(), n = word2.size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(int j=0; j<=n; j++){
            dp[m][j] = abs(n-j);
        }
        
        for(int i=0; i<=m; i++){
            dp[i][n] = abs(m-i);
        }
        
        for(int i = m-1; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                if(word1[i] == word2[j]) dp[i][j] = dp[i+1][j+1];
                else dp[i][j] = min(dp[i+1][j+1], min(dp[i][j+1], dp[i+1][j]))+1;
            }
        }
       
        
        return dp[0][0];
    }
    //T - O(m*n)
    //S - O(m*n)
   
};
