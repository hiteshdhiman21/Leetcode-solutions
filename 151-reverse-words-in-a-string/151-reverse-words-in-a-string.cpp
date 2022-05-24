class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int ecr = s.size()-1;
        for(int i=s.size()-1; i>=0; i--){
            if((i==0 || s[i-1] == ' ') && s[i] != ' '){
                if(ecr-i+1 > 0){
                    ans += s.substr(i, ecr-i+1);
                    ans += " ";
                }
            }
            
            if(s[i] == ' ') ecr = i-1;
        }
        
        ans.pop_back();
        return ans;
    }
};