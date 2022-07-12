class Solution {
public:
    void add(string& res, string& s){
        int i = 0;
        int c = 0;
        
        for(int i=0; i<res.size() || i<s.size() || c!=0; i++){
            int sum = c;
            if(i<res.size()) sum += res[i]-'0';
            if(i<s.size()) sum += s[i]-'0';
            
            c = sum/10;
            sum = sum%10;
            if(i<res.size())
            res[i] = sum+'0';
            else
            res.push_back(sum+'0');
        }
    }
    
    string multiply(string num1, string num2) {   
       
        if(num1 == "0" || num2=="0") return "0";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        string res = "";
        
        for(int i=0; i<num2.size(); i++){
            string row = "";
            for(int time=0; time<i; time++) row += "0";
            int c = 0;
            for(int j=0; j<num1.size() || c!=0; j++){                
                int prod = c;
                if(j<num1.size()) prod += (num2[i]-'0')*(num1[j]-'0');
                c = prod/10;
                prod = prod%10;
                cout << prod << endl;
                row.push_back(prod+'0');
               
            }
            
            add(res, row);
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
    //T - O(m*n)
    //S - O(m+n)
    
};