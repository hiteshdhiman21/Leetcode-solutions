class Solution {
public:
    int characterReplacement(string s, int k) {
        
      /*Intuition: Originally Use sliding window for all 26 different character. But we can also make use of mostFrequent frequency and some facts about how the algorithm will work.
      Fact 1: For substring to be valid, substring len - most Frequent charcter <= k. (i.e, the min characters to make string valid <= k).
      Fact 2: Higher the most frequent character, Higher the valid substring length.
      Fact 3: If we have calculated fully(i.e len - most Frequent charcter > k condition fails and then we increment left) maxLength for some mostFrequent frequency, then in future the maxLength for same mostFrequentCharater <= maxLength already calculated.
      Fact 4: If in future, the mostFrequent frequency decrease in relatity but we don't do that in algorithm. Then no need to worry as problem is asking for maxLength and decreased mostFrequent frequency will give some less length now onward but the same mostFrequent frequency will give the same or <= maxLength calculated and in Both the cases(reality or algorithm), the ans = maxLength caclulated.
      Fact 5: If in future, the mostFrequent frequency increases in reality then we will also increase it in algorithm and Therefore it would result into greater maxLength in that case only.
      Fact 6: Hence we only need to consider changing(only increasing if it is high in current substring as decreasing and remain same will not change ans) mostFrequency while incrementing right and we not need to decrease while decrementing left pointer
      */
        
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
            
            maxLength = max(maxLength, right-left+1);
        }
        
        return maxLength;
    }
    //T - O(n)   
    //S - O(26)
};