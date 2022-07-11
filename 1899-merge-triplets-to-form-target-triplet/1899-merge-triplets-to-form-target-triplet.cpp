class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool f = false, s = false, t= false;
        for(auto& _: triplets){
            if(_[0] <= target[0] && _[1] <= target[1] && _[2] <= target[2]){
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