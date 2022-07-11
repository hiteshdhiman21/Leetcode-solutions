class Solution {
public:
    bool checkValidString(string s) {
        int openMx = 0, openMn = 0; //These represents a valid range of open parenthesis
        for(char& ch: s){
            if(ch == '(') openMx++, openMn++;
            else if(ch == ')') openMx--, openMn--;
            else openMn--, openMx++;
            
            if(openMn < 0) openMn = 0; //Just change old perception of '*' from ')' to '' and then '('.
            if(openMx < 0) return false; //Can't change old perception. Because we already treated '*' as '(' and still it became negative.
        }
        
        return openMn==0;
    }
    //T - O(n)
    //S - O(1)
};