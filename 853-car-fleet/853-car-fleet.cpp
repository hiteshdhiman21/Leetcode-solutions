class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> posSpeed;
        
        for(int i = 0; i < n; i++){
            posSpeed.push_back({position[i], speed[i]});
        }
        
        sort(posSpeed.begin(), posSpeed.end());
        
        
        
        int cnt = 0;
        long lastDistRem = 0;
        long lastSpeedRem = 1;
        
        for(int i = n-1; i>=0; i--){
            long curDistRem = target-posSpeed[i].first,
                curSpeedRem = posSpeed[i].second;
            
            //curTime > lastTime
            if(curDistRem*lastSpeedRem > lastDistRem*curSpeedRem){
                cnt++;
                lastDistRem = curDistRem;
                lastSpeedRem = curSpeedRem;
            }
        }
        
        return cnt;
    }
};