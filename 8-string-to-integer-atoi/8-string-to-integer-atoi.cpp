class Solution {
public:
    int myAtoi(string s) {
       
        //Step-1. Take 'i' to just bypass the leading spaces and sign if any.
        //Step-2. Now start from the back to just before the spaces and sign at the start and start converting into interger (as we can see from the end if it is valid or not. If not valid we can just make ans = 0 and restart from before that index). It will also help in maintaining mul_fac as required.
        
        //Step-3. Beware of cases like positive or negative integer overflow. Two signs.  spaces between the numbers.
        //Cases : _4, _-+45, _+4 76, _4word are therein, _+0923099120202_9.
        
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
            if(!isdigit(s[j])){ //If invalid just reset the ans and mul_fac again
                ans = 0;
                mul_fac = 1;
            }else{
                int dig = s[j]-'0';
                
                //Below steps are To prevent overflow of long long and still reach INT_MAX 
                if(ans <= INT_MAX) 
                ans += dig*mul_fac; 

                if(mul_fac != 1e10) mul_fac  *= 10; 
            }
        }
        
        if(sign == -1){
            if(ans > INT_MAX) ans = INT_MIN;//more than INT_MAX have to convert into INT_MIN
            else ans = -ans; //we just have to negate the sign for <= INT_MAX
            return ans;
        }
        
        return min((long long)INT_MAX, ans);
    }
};