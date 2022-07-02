class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
      /*Fact: Every car max will only be be able to join the car fleet before it and not any other. Thererefore we will iterate rom the last, since the car at the last index(max position) will be before all the cars.
        Step-1. Convert the storage format for {position, speed} so that we can sort according to position of each car.
        Step-2. If the time taken for current car is > time taken for fleet before the current car. Then this car will not be able to join that fleet and Hence it will start its new fleet. Hence do cnt++ and for cars behind it update the lastFleetTimeTaken = curCarTimeTaken.
                (we are using dist and speed for it to avoid precision error)
        Step-3. Else, it means this car can join the fleet before it. Hence it will join it and  time taken for it will become equal to the time taken for fleet(Because it will slow down to speed of next fleet). Hence Don't update the cnt.
        Step-4. Finally return the cnt.*/
        
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
    //T - O(nlogn)
    //S - O(n) or O(1) depending upon the input format
    
};