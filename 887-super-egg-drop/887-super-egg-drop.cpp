class Solution {
public:
    int superEggDrop(int n, int k) {
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
        
        vector<vector<int>> dp(n+1, vector<int> (k+1));
        
        for(int f=1; f<=k; f++) dp[1][f] = f;
        for(int e=1; e<=n; e++) dp[e][1] = 1;
        
        for(int e=2; e<=n; e++){
            for(int f=2; f<=k; f++){
                //Using binary search to find the Best out of Worst
                int botw = INT_MAX;
                
                int start = 1;
                int end = f;
                
                while(start <= end){
                    int edf = start+(end-start)/2;
                    int belowAns = dp[e-1][edf-1]; //It increases with edf as no. of floors increases
                    int aboveAns = dp[e][f-edf]; //It decreases with edf as no. of floors decreases
                    
                    if(belowAns < aboveAns){
                        botw = aboveAns;
                        start = edf+1; 
                    }else if(belowAns > aboveAns){
                        botw = belowAns;
                        end = edf-1; 
                    }else{
                        botw =belowAns;
                        break;
                    }
                }
                
                dp[e][f] = botw+1;
            }
        }
    
        return dp[n][k];
    }
    //T - O(n*k*log(k))
    //S - O(n*k)
};