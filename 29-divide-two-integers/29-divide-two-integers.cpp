class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
        bool isPositive = (dividend>0 == divisor>0);
        unsigned int a = abs(dividend), b = abs(divisor);
        
        unsigned int ans = 0;
        while(a>=b){
            
            int q = 0;
            while(q<31 && a>(b<<(q+1))) q++; //Means a >= b*pow(2, q+1)
            
            ans += (1<<q);
            a -= (b<<q);
        }
        if(ans == (1<<31) && isPositive) return INT_MAX;
        else return ans*(isPositive?1:-1);
    
    }
    //T - O(32+31+30+....1) = O(nBits*nBits)
    //S - O(1)
};