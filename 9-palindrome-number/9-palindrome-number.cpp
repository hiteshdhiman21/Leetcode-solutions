class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x < 0 || x!= 0 && x%10 == 0) return false;
        
        int xOrig = x;
        int xRev = 0;
        
        while(xOrig > xRev){     
            
            xRev = xRev*10 + xOrig%10;
            xOrig /= 10;
            
        }
        
        //Checking for even and odd no of digits.
        return xOrig == xRev || xOrig == xRev/10;
    }
    //T - O(10)
    //S - O(1)
};