class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
      /*Approach: Greedy 
        Step-1. Choosing only those triplets which may not make the ans bad.
        Step-2. Out of those triplets if target values are present in the corresponding indices
                Then the ans is true. Else false*/
        bool f = false, s = false, t= false;
        for(auto& _: triplets){
            if(_[0] <= target[0] && _[1] <= target[1] && _[2] <= target[2]){
                //Choosing only those triplets which will not make the ans bad
                if(_[0] == target[0]) f = true;
                if(_[1] == target[1]) s = true;
                if(_[2] == target[2]) t = true;
            }
        }
        
        return f&&s&&t;
    }
    //T - O(n)
    //S - O(1)
};