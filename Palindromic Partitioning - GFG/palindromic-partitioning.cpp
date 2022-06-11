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
      /*Step-1. Set dp[n] = 0. As string of length 0 have 0 partitions.
        Step-2. For all i starting from the last Index, try to check for all palindromic substrings(ending at j). Set dp[i] = min(dp[i], 1+dp[j+1])
                '1' added because we are partitioning the string at index j.
        Step-3. Finally return dp[0]-1. because all dp[ind] stores an additional count for partition line after the last character which is separating
                substring before from the empty string. storage is like this ababa|cfgfc|lol| but the last line is not needed.*/ 
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
    //T - O(n^2)
    //S - O(n)
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