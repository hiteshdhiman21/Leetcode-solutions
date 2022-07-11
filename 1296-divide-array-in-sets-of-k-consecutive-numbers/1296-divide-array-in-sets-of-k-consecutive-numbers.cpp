class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
      /*Approach: Greedy
        Step-1. Make a freq map of nums elements so that we can take a minimum element for every round. And easily remove the taken element in O(logn)
        Step-2. While freq.size() > 0, Take mn element from the map(as it will always start a new round). And check if k consecutive elements including mn are present in the array. If not. Return false.
        Else go for another round.
        Step-3. Finally if freq.size() == 0. It means that for every round there are k consecutive elements. Hence return true.*/
        
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