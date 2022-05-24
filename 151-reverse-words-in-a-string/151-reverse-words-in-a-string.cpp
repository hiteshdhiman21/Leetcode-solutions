class Solution {
public:
    string reverseWords(string s) {
        //Step-1. Starting from the last and trying to find end and start for each word if present.
        //Step-2. If found, appending that word(substring) to the ans with a ' '
        string ans;
        int ecr = s.size()-1;
        for(int i=s.size()-1; i>=0; i--){
            if((i==0 || s[i-1] == ' ') && s[i] != ' '){
                if(ecr-i+1 > 0){
                    ans += s.substr(i, ecr-i+1);
                    ans += " ";
                }
            }
            
            if(i>0 && s[i] == ' ' && s[i-1] != ' ') ecr = i-1;
        }
        
        ans.pop_back();
        return ans;
    }
    //T - O(n)
    //S - O(n) for making ans
};