class Solution {
public:
    int getSum(int a, int b) {
        //a+b = a^b + ((a&b)<<1). Because carry have effect on left side bit. Then again as we can't simply add them both. We will add them using this operation. Finally we will stop when b==0.
        while(b){
            int na = a^b;
            b = (unsigned int)(a&b)<<1;
            a = na;
        }
        
        return a;
        
    }
    //T - O(1)
    //S - O(1)
};