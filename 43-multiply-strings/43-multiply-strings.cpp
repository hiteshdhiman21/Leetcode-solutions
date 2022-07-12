class Solution {
public:
    
    string multiply(string num1, string num2) {   
       
        if(num1 == "0" || num2=="0") return "0";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        string res(num1.size()+num2.size(), '0');
        
        for(int i=0; i<num2.size(); i++){
            int prodCarry = 0, sumCarry = 0;
            
            for(int j=0; j<num1.size() || prodCarry!=0 || sumCarry != 0; j++){ 
                int prod = prodCarry;
                if(j<num1.size()) prod += (num2[i]-'0')*(num1[j]-'0');
                prodCarry = prod/10;
                prod = prod%10;
                
                int sum = res[i+j]-'0' + sumCarry + prod;
                sumCarry = sum/10;
                sum = sum%10;
                
                res[i+j] = sum+'0';
            }
        }
        
        while(res.size() > 1 && res.back() == '0') res.pop_back();
        
        reverse(res.begin(), res.end());
        return res;
    }
    //T - O(m*n)
    //S - O(1)
    
};