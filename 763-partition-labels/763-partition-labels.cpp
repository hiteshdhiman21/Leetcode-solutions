class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastInd(26, 0);
        for(int i=0; i<s.size(); i++)
            lastInd[s[i]-'a'] = i;
        
        int start = 0, end=0;
        vector<int> res;
        for(int i=0; i<s.size(); i++){
            end = max(end, lastInd[s[i]-'a']);
            if(end == i){
                res.push_back(end-start+1);
                start = end = i+1;
            }
        }
        
        return res;
    }
    //T - O(n)
    //S - O(26)
};