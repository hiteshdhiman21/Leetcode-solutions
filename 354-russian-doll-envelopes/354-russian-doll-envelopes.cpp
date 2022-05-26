

class Solution {
public:
    static bool compare(vector<int>&a , vector<int>& b)
    {
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //Sort whole array with respect to first element in non-decreasing order and for same values of first elements sort second elements in decreasing order. So that i don't pick the elements with same width twice.
        //Then apply LIS on second elements and get the ans as LIS.
        sort(envelopes.begin(), envelopes.end(), compare);
        
        vector<int> temp;
        temp.push_back(envelopes[0][1]);
        for(int i=1; i<envelopes.size(); i++){
            if(temp.back() < envelopes[i][1]) temp.push_back(envelopes[i][1]);
            else{
                int tempInd = lower_bound(temp.begin(), temp.end(), envelopes[i][1])-temp.begin();
                temp[tempInd] = envelopes[i][1];
            }
        }
        
        return temp.size();
    }
    //T - O(nlogn) for sorting and binary searching on every index
    //S - O(n)
};