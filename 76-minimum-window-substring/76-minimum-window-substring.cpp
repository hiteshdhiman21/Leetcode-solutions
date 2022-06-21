class Solution {
public:
    string minWindow(string s, string t) {
        
        vector<int> freq(256, 0);
        
        for(char& ch: t) 
            freq[ch]++;
        
        int minLen = INT_MAX;
        int minStart = -1;
        
        int i = 0, j = 0;
        while(j < s.size()){
            freq[s[j]]--;
            
            bool ok = true;
            for(int &f: freq)
                if(f > 0) ok = false;
            
            if(ok){
                while(i<=j){
                    if(j-i+1 < minLen){
                        minLen = j-i+1;
                        minStart = i;
                    }
                    freq[s[i]]++;
                    i++;
                    if(freq[s[i-1]] > 0) break;
                }
            }
            j++;
        }
        
        if (minLen == INT_MAX)
            return "";
        else
            return s.substr(minStart, minLen);
    }
    //T - O(n)
    //S - O(256)
};