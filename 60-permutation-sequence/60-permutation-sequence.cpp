class Solution {
public:
    string getPermutation(int n, int k) {
        vector<bool> numAvailable(n+1, true);
        vector<int> impact(n+1, 1);
        
        impact[n] =1;
        for(int i=n-1; i>=1; i--) impact[i] = impact[i+1]*(n-i+1);
        
        string ans;
        k--;
        for(int ind=1; ind<=n; ind++){
            int posFind = 1;
            if(k!=0) posFind = k/impact[ind+1]+1;
            
          //  cout << posFind << " " << numFind << " " << k << endl;
            
            int numFind = 1;
            
            int cnt = 0;
            for(int num = 1; num <= n; num++){
                if(numAvailable[num]) cnt++;
                
                if(cnt >= posFind){
                    numFind = num;
                    break;
                }
            }
            
            ans.push_back(numFind+'0');
            numAvailable[numFind] = false;
            
            if(k > 0)
            k = k%impact[ind+1];
            
            //cout << posFind << " " << numFind << " " << k << endl;
        }
        
        return ans;
    }
};