class Solution {
public:
    int myAtoi(string s) {
       
        int i =0;
        while(i<s.size()){
            if(s[i] != ' ') break;
            i++;
        }
        int sign = 1;
        if(s[i] == '+'){
            sign = 1;
            i++;
        }else if(s[i] == '-'){
            sign = -1;
            i++;
        }
        
        long long ans = 0;
        long long mul_fac = 1;
        
        for(int j = s.size()-1; j>=i; j--){
            if(!isdigit(s[j])){
                ans = 0;
                mul_fac = 1;
            }else{
            
                int dig = s[j]-'0';
                if(ans <= INT_MAX)
                ans += dig*mul_fac;
                
                
                if(mul_fac != 1e10) mul_fac  *= 10;
            }
        }
        
        if(sign == -1){
            if(ans > INT_MAX) ans = INT_MIN;
            else ans = -ans;
            return max((long long)INT_MIN, ans);
        }
        
        return min((long long)INT_MAX, ans);
    }
};