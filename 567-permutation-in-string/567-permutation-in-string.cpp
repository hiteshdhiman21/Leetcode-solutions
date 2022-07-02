class Solution {
public:
    bool checkInclusion(string& s1, string& s2) {
        vector<int> freq(26, 0);
        
        int cntMatchedAlphabets = 0;
        for(char &ch: s1)
            freq[ch-'a']++;
        
        for(int i =0; i<26; i++)
            if(freq[i] == 0)
                cntMatchedAlphabets++;
        
        int k = s1.size();
        
        for(int i = 0; i<s2.size(); i++){
            freq[s2[i]-'a']--;
            
            if(freq[s2[i]-'a'] == 0) cntMatchedAlphabets++;
            
            if(i>=k){
                freq[s2[i-k]-'a']++;
                if(freq[s2[i-k]-'a'] == 1)
                    cntMatchedAlphabets--;
            }
            
            if(cntMatchedAlphabets == 26) return true;
        }
        
        return false;
    }
    //T - O(n) , Not O(26n) using this technique
    //S - O(26)
};