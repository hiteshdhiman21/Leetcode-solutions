class Solution {
public:
    bool checkValidString(string s) {
        int openMx = 0, openMn = 0; //These represents a valid range of open parenthesis
        for(char& ch: s){
            if(ch == '(') openMx++, openMn++;
            else if(ch == ')') openMx--, openMn--;
            else openMn--, openMx++;
            
            if(openMn < 0) openMn = 0;
            if(openMx < 0) return false;
        }
        
        return openMn==0;
    }
};