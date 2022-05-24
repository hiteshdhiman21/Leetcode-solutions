class Solution {
public:
    
    unordered_map<int, string> m = { {1000, "M"}, {500, "D"}, {100, "C"}, {50, "L"}, {10, "X"},{5, "V"}, {1, "I"},
                                  {900, "CM"}, {400, "CD"}, {90, "XC"}, {40, "XL"}, {9, "IX"}, {4, "IV"}};
    
    
    string intToRoman(int num) {
        string s = to_string(num);
        int mul_fac = 1;
        for(int i=0; i<s.size()-1; i++){
            mul_fac *= 10;
        }
        
        string ans = "";
        for(int i=0; i<s.size(); i++){
            int dig = s[i]-'0';
            int used = 0;
            if(dig == 4 || dig ==9){
                ans += m[dig*mul_fac]; used = dig;
            }else if(dig >= 5 && dig <= 9){
                ans += m[5*mul_fac]; used = 5;
            }
            
            while(used < dig){
                ans += m[mul_fac];
                used++;
            }
            mul_fac /= 10;
        }
        return ans;
    }
};