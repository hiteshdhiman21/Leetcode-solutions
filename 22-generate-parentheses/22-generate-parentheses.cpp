class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        for(int i = 0; i<(1<<(2*n)); i++){
            string cur = "";
            int cnt = 0;
            for(int x = 0; x<2*n; x++){
                if(i&(1<<x)){
                    cur += "(";
                    cnt++;
                }else{
                    cur += ")";
                    cnt--;
                }
                
                if(cnt < 0) break;
            }
            
            if(cnt == 0) res.push_back(cur);
        }
        return res;
    }
    //T - O(2^(2n))
    //S - O(n)
};