class Solution {
public:
    vector<string> generateParenthesis(int n) {
      /*DP-Bitmasking
        Generate all possible parenthesis combinations but add only valid ones to our res vector*/
        vector<string> res;
        for(int i = 0; i<(1<<(2*n)); i++){
            string cur = "";
            int balance = 0;
            for(int x = 0; x<2*n; x++){
                if(i&(1<<x)){
                    cur += "(";
                    balance++;
                }else{
                    cur += ")";
                    balance--;
                }
                
                if(balance < 0 || balance > 2*n-1-x ) break;
            }
            
            if(balance == 0) res.push_back(cur);
        }
        return res;
    }
    //T - O(n*2^(2n))
    //S - O(n)
};