class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       /*Approach: Dynamic Programming
        Step-1. First update all the cells distances using just top-left directions.
        Step-2. Then update all the cells distances using just bottom-right directions. In this step all the cells will be updated wrt all 4 directions. Consider 4 cases: 0 present only in Top-left, Bottom-right, Top-right, Bottom-left.
        Step-3. Finally return the array*/
        
        int n = mat.size(), m = mat[0].size(), INF = n+m; 
        
        //Top-left
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0) continue;
                mat[i][j] = INF;
                
                if(i-1 >= 0) mat[i][j] = min(mat[i][j], mat[i-1][j]+1);
                if(j-1 >= 0) mat[i][j] = min(mat[i][j], mat[i][j-1]+1);
            }
        }
        
        //Bottom-right
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(mat[i][j] == 0) continue;
                
                if(i+1 < n) mat[i][j] = min(mat[i][j], mat[i+1][j]+1);
                if(j+1 < m) mat[i][j] = min(mat[i][j], mat[i][j+1]+1);
            }
        }
        
        return mat;
    }
    //T - O(n)
    //S - O(1) (Did inplace)
    //There is one more method using BFS (but it requires S - O(n*m))
};