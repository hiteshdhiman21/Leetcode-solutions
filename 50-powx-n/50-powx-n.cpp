class Solution {
public:
    double myPow(double x, int n) {
        long nn = abs(n);
        
        double ans = 1;
        while(nn>0){
            if(nn&1){
                ans = ans * x;
                nn--;
            }else{
                x =x*x;
                nn/=2;
            }
        }
        
        if(n<0)
            return 1.0/ans;
        else
            return ans;        
    }
};