// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    bool isPal(string &str, int s, int e){
        while(s<e){
            if(str[s++] != str[e--]) return false;
        }
        return true;
    }

    int palindromicPartition(string str)
    {
        int n = str.size();
        
        vector<int> dp(n+1, n);
        dp[n] = 0;
        
        for(int i = n-1; i>=0; i--){
            for(int j=i; j<=n-1; j++){
                if(isPal(str, i, j)){
                    dp[i] = min(dp[i], dp[j+1]+1);
                }
            }
        }
        
        return dp[0]-1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends