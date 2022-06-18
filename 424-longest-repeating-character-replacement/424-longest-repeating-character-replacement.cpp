class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int mostFrequent = 0;
        int maxLength = 0;
        int left = 0;
        
        for(int right = 0; right < s.size(); right++){
            freq[s[right]-'A']++;
            mostFrequent = max(mostFrequent, freq[s[right]-'A']);
            if(right-left+1-mostFrequent > k){
                freq[s[left]-'A']--;
                left++;
            }
            
           // cout << left << " " << right << " " << mostFrequent << endl;
            
            maxLength = max(maxLength, right-left+1);
        }
        
        return maxLength;
    }
    //T - O(26n)
    //S - O(k)
};