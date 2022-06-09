// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int solve(int i, int j, int arr[], vector<vector<int>>& dp){
        if(i==j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int mn = INT_MAX;
        for(int k = i; k <= j-1; k++){
            int mulOuter = arr[i-1]*arr[k]*arr[j];
            int mulInner = solve(i, k, arr, dp) + solve(k+1, j, arr, dp);
            mn = min(mn, mulOuter+mulInner);
        }
        
        return dp[i][j] = mn;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        /*
        len -> no. of matrices.  i ->  first matrix.   j ->  last matrix
        For any ith matrix M[i] -> arr[i-1] and arr[i] are its dimensions
        */
        
        /*
        Step-1. For len = 1, set all possible dp[i][j] = 0; 
        Step-2. Now start calculating in increasing order of len . Because dp[len] depends on dp[some smaller len]. Start k from i till j-1. Because k
                is the partition index. M[i]*M[i+1]*****M[k]*M[k+1]*M[k+2]***M[j]. so dp[i][j] = min(dp[i][k]+dp[k][j]+arr[i-1]*arr[k]*arr[j]).
                where partitioning is like  M[i]*M[i+1]*****M[k]  and M[k+1]*M[k+2]***M[j] or(arr[i-1, i, ...., k] and arr[k+1, .....j]).
        Step-3. Finally return dp[1][N-1]. Because there are total N-1 matrices.
        */
        vector<vector<int>> dp(N, vector<int> (N, 0));
        
        for(int len = 2; len <= N-1; len++){
            for(int i = 1; i<=N-len; i++){
                int j = i+len-1;
                
                int mn = INT_MAX;
                for(int k = i; k <= j-1; k++){
                    int mulOuter = arr[i-1]*arr[k]*arr[j];
                    int mulInner = dp[i][k] + dp[k+1][j];
                    mn = min(mn, mulOuter+mulInner);
                }
                dp[i][j] = mn;
            }
        }
        
        return dp[1][N-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends