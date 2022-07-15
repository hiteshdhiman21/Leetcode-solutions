class Solution {
public:
    int gcd(int a, int b) { 
    if(b==0)
        return a;
    return gcd(b, a%b);
    } 

    int maxPoints(vector<vector<int>>& points) {
        int res = 1;
        
        for(int i=0; i<points.size(); i++){
            map<pair<int, int>, int> freqSlope;
            for(int j=i+1; j<points.size(); j++){
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                int dx = (x2-x1), dy = (y2-y1);
                if(dx < 0) dx = -dx, dy = -dy;
                
                int g = gcd(dx, dy);
                dx /= g; dy /= g; 
                //It also handles infnite slope case by (1,0) and 0 slope by (0, 1).
                
                freqSlope[{dx, dy}]++;
                res = max(res, freqSlope[{dx, dy}]+1);
            }
        }
        
        return res;
    }
    //T - O(n*n)
    //S - O(n)
};