class Solution {
public:
    int minAddToMakeValid(string s) {
        int res = 0;
        int open = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(') open++;
            else open--;
            
            if(open < 0) res++, open = 0;
        }
        
        return res+open;
    }
};