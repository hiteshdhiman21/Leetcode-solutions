class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        
        if(nums.size()%k != 0) return false;
        
        map<int, int> freq;
        for(int x: nums)
            freq[x]++;
        
        while(freq.size()){
            int mn = freq.begin()->first;
            for(int i = 0; i<k; i++){
                if(freq.count(mn+i) == 0)
                    return false;
                freq[mn+i]--;
                if(freq[mn+i] == 0) freq.erase(mn+i);
            }            
        }
        
        return true;
    }
    //T - O(nlogn)
    //S - O(n)
};