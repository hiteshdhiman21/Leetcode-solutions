class Solution {
    
public:
    
    bool check(vector<int> &bloomDay, int m, int k, int day){
        int cntBouquet = 0, cntFlowers = 0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= day) cntFlowers++;
            else cntFlowers = 0;
            
            if(cntFlowers == k){
                cntBouquet++;
                cntFlowers = 0;
            }
        }

        return cntBouquet >= m;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        /*Approach: Binary search
        Same like aggressive cows*/
        
        int n = bloomDay.size();
        if(m*k > n) return -1;
        
        int start = 0, end = 1e9;

        int time = 0;
        while(start <= end){
            int mid = start+(end-start)/2;
            if(check(bloomDay, m, k, mid)){
                time = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        } 

        return time;
    }
    //T - O(nlog(1e9))
    //S - O(1)
};