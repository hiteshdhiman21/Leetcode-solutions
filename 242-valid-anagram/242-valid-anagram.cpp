class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26, 0);
        
        for(char &ch: s)
            freq[ch-'a']++;
        
         for(char &ch: t)
            freq[ch-'a']--;
        
        for(int f: freq)
            if(f != 0) return false;
        
        return true;
    }
    //T - O(n)
    //S - O(26)
    
};