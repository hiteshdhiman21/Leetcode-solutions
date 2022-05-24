class Solution {
public:
    string longestPalindrome(string s) {
        
        //Intuition: Fix each element as a center and try to expand the string maintaining it a center. Then Fix each and its next element as a center and try to expand the string maintaining them a center. 
        //If s[left] == s[right], do left--, right++. else break.
        //Compare the len with max_len. If len>max_len update max_len = len and start = left+1
        
        int max_len = 0;
        int start = -1;
        for(int i=0; i<s.size(); i++){
            
            //generating odd-length substring
            int left = i-1, right = i+1;
            while(left>=0 && right < s.size()){
                if(s[left] != s[right]) break;
                left--; right++;
            }
            if(right-left-1 > max_len){
                max_len = right-left-1;
                start = left+1; //Becuase at left the character became unequal
            }
            
            //generating even-length substring
            left = i, right = i+1;
            while(left>=0 && right < s.size()){
                if(s[left] != s[right]) break;
                left--; right++;
            }
            if(right-left-1 > max_len){
                max_len = right-left-1;
                start = left+1;
            }
        }
        return s.substr(start, max_len);
    }
    //T - O(n^2)
    //S - O(1)
};