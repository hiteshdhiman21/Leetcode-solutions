// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        //Binary search
        //Like if v4 is bad, then v5 v6 ... vn are also bad but if v4 is fine, then v1 v2 v3 is also fine.
        int s = 1, e= n;
        int ans = -1;
        while(s <= e){
            int m = s + (e-s)/2;
            
            if(isBadVersion(m)){
                ans = m;
                e = m-1;
            }else{
                s = m+1;
            }
        }
        return ans;
    }
    //T - O(logn)
    //S - O(1)
};