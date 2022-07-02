class Solution {
public:
    
    int eatHours(vector<int>& piles, int mid){
        
        int hours = 0;
        for(int& x: piles){
            if(x%mid == 0)
            hours += x/mid;
            else
            hours += x/mid+1;
            
            if(hours > 1e9) return hours;
        }
        
        return hours;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
      /*Classical Binary search problem: Agressive cows*/
        int s = 1, e = 1e9;
        int k = -1;
        while(s<=e){
            int mid = s+(e-s)/2;
            
            if(eatHours(piles, mid) <= h){
                k = mid;
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        
        return k;
    }
    //T - O(nlogm), where n = piles.length() and m = max(piles[i])
    //S - O(1)
};