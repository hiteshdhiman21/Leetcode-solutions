#define vvvi(v, n, m, p, val) vector<vector<vector<int>>>  v(n, vector<vector<int>>(m, vector<int>(p, val)));
#define ll long long
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
      /*Approach: 3D DP
        2D DP by calculating for both robots sepately wouldn't work. See the following case [[1 1 1] [4 4 1]].
        Therefore we have to use both the robots simultaneously.*/
        
        int n = grid.size(), m = grid[0].size();
        vvvi (dp, n+1, m, m, 0);
        
        for(int i=n-1; i>=0; i--){
            for(int j1=0; j1<m; j1++){
                for(int j2=0; j2<m; j2++){
                    for(int plus1=-1; plus1<=1; plus1++){
                        int nj1 = j1+plus1;
                        for(int plus2=-1; plus2<=1; plus2++){
                            int nj2 = j2+plus2;
                            
                            if(nj1 == -1 || nj1 == m || nj2 == -1 || nj2 == m) continue;
                            if(j1 != j2)
                                dp[i][j1][j2] = max(dp[i][j1][j2], dp[i+1][nj1][nj2]+grid[i][j1] + grid[i][j2]);
                            else
                                dp[i][j1][j2] = max(dp[i][j1][j2], dp[i+1][nj1][nj2]+grid[i][j1]);
                        }
                    }
                }
            }
        }
        
        return dp[0][0][m-1];    
    }
    //T - O(n*m*m)
    //S - O(n*m*m) can be optimized to O(m*m)
};

   