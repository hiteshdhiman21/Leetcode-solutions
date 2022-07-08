class Solution {
public:
    int numSplits(string s) {
        vector<int> freq1(26), freq2(26);
        
        int cntDiff1 = 0, cntDiff2 = 0;
        for(char ch: s){
            freq2[ch-'a']++;
            if(freq2[ch-'a'] == 1)
                cntDiff2++;
        }
        
        int res = 0;
        
        // i<s.size()-1 because at i == s.size()-1, S2 will have 0 characters
        for(int i = 0; i<(int)s.size()-1; i++){ 
            freq1[s[i]-'a']++;
            if(freq1[s[i]-'a'] == 1)
                cntDiff1++;  
            
            freq2[s[i]-'a']--;
            if(freq2[s[i]-'a'] == 0)
                cntDiff2--;
            
            if(cntDiff1 == cntDiff2)
                res++;
        }
            
        return res; 
    }
    //T - O(n)
    //S - O(26)
};