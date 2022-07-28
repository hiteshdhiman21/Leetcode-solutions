class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x < 0) return false;
        
        int xOrig = x;
        int xRev = 0;
        
        while(x){     
            
            if(xRev>INT_MAX/10 || (xRev == INT_MAX/10 && x%10 > 7))
                return false;
            
            xRev = xRev*10 + x%10;
            x /= 10;
            
        }
        
        return xOrig == xRev;
    }
    //T - O(10)
    //S - O(1)
};