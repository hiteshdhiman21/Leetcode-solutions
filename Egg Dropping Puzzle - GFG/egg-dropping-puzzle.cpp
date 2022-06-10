// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
      /*Points to be considered:
        1. We don't need to find the critical floor.
        2. We just need to find the BEST OUT OF THE WORST strategy(Althought not return the strategy. 
            Just return the worst case scenario in the best strategy).
        3. Suppose there is S1(1, 100), S2(10, 60), S3(80, 100), S4(30, 40) of type S(best_time, worst_time). So, we need to find the strategy which
            work best even in the worst case and we will choose S4. (Don't go with that famous hindi idiom: "Bani to Bani __ ")
        */  
        
      /*Steps: 
        1. For every given eggs e and Floors f. There can be 2 cases after dropping the egg at some floor edf.
            Case-1: Egg breaks: In that case critical floor is current floor or downward for sure (Cf <= edf). So we have to check k-1 floors using 
                    e-1 eggs. i.e. (e-1, edf-1)
            Case-2: Egg survives: In that case critical floor is upward for sure (Cf > edf). So we have to check upper f-k floors using 
                    e eggs. i.e. (e, f-edf)
                    
            So any of the 2 cases can be worst or the best and we can't be sure which will happen(as we don't know the critical floor location)
            So, we will consider only the worst case.
        2. We will find worst case attempts(out of the two) for each floor and set best ans of this floor to be equal to min(all worstCase attempts) + 1.
            where, 1 is for dropping. (And we have the strategy for current (e, f), i.e. for it drop the egg on the floor with min worst case attempts )
        3. We will calculate ans for all possible (e, f) and using some (e, f), calculate for many others (e<, f<). Therefore we will use DP for 
            storing and calculation.
        4. Finally return dp[e][f]
        */ 
        
        vector<vector<int>> dp(2, vector<int> (k+1));
        
        for(int f=1; f<=k; f++) dp[1%2][f] = f;
        
        
        for(int e=2; e<=n; e++){
            dp[e%2][1] = 1;
            for(int f=2; f<=k; f++){
                int botw = INT_MAX;
                for(int edf=1; edf<=f; edf++){
                    int worst = max(dp[(e-1)%2][edf-1], dp[e%2][f-edf]);
                    botw = min(botw, worst);
                }
                dp[e%2][f] = botw+1;
            }
        }
    
        return dp[n%2][k];
    }
    //T - O(nEggs*nFloors*nFloors)
    //S - O(2*nFloors)
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends