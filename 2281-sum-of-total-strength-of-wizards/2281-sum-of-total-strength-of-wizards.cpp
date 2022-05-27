class Solution {
public:
    int totalStrength(vector<int>& strength) {
        int n = strength.size();
        int mod = 1e9+7;
        vector<int> left(n); //Till what index in left is included for every index.
        vector<int> right(n); //Till what index in right is included for every index.
        
        stack<int> st;
        for(int i = 0; i<n; i++){
            while(!st.empty() && strength[st.top()] >= strength[i]){
                st.pop();
            }
            if(st.empty()) left[i]=0;
            else left[i] = st.top()+1;
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && strength[st.top()] > strength[i]){
                st.pop();
            }
            if(st.empty()) right[i]=n-1;
            else right[i] = st.top()-1;
            st.push(i);
        }
        
        vector<int> prefSum(n, 0);
        int sum = 0;
        for(int i=0; i<n; i++){
            sum = (sum + (long)strength[i])%mod;
            prefSum[i] = sum;
        }
        
        vector<int> pPrefSum(n, 0);
        sum = 0;
        for(int i=0; i<n; i++){
            sum = (sum + (long)prefSum[i])%mod;
            pPrefSum[i] = sum;
        }
        
        long ans = 0;
        for(int i = 0; i < n; i++){
            int r = right[i], l = left[i];
            //cout << i << " " << l  << " " << r << " :   ";
            
            int posSum = pPrefSum[r];
            if(i > 0) posSum -= pPrefSum[i-1];
    
            int posCon = ((long)posSum*(i-l+1))%mod;
            
            int negSum = 0;
            if(i>0) negSum += pPrefSum[i-1];
            if(l>1) negSum -= pPrefSum[l-2];  
            int negCon = ((long)negSum*(r-i+1))%mod;
            
            //cout << posSum << " " << posCon << " " << negSum << " " << negCon << endl;
            ans = (ans + ((((long)posCon-negCon+mod)%mod)*(long)(strength[i]))%mod)%mod;
            
        }
        
        return ans;
    }
};