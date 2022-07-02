class Solution {
public:
    bool checkInclusion(string& s1, string& s2) {
        vector<int> freq(26, 0);
        for(char &ch: s1)
            freq[ch-'a']++;
        
        int k = s1.size();
        
        for(int i = 0; i<s2.size(); i++){
            freq[s2[i]-'a']--;
            if(i>=k)
                freq[s2[i-k]-'a']++;
            
            bool ok = true;
            for(int i =0; i<26; i++)
                if(freq[i] != 0)
                    ok = false;
                
            if(ok) return true;
        }
        
        return false;
    }
    //T - O(n)
    //S - O(26)
};