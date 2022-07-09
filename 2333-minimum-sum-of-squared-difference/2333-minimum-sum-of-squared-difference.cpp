using ll = long long;


class Solution {
public:
    
    ll check(vector<ll> &diff, int n, ll m){
        ll op = 0;
        for(int i = 0; i< n; i++){
            op += max(0ll, diff[i]-m);
        }
        return op;
    }
    
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<ll> diff(n);
        
        ll k = k1+k2;
        
        for(ll i = 0; i < n; i++)
            diff[i] = abs(nums1[i] - nums2[i]);
        
        sort(diff.begin(), diff.end());
        
        ll s = 0, e = diff.back();
        
        ll confirmed = 0;
        ll op = 0;
        while(s <= e){
            
            ll m = s+(e-s)/2;
            ll opNeed = check(diff, n, m);
            //cout << s << " " << e << " " << opNeed<< " " << confirmed << endl;
            if(opNeed <= k){
                confirmed = m;
                op = opNeed;
                e = m-1;
            }else{
                s = m+1;
            }
        }
        
        for(ll i = n-1; i>=0; i--){
            diff[i] = min(diff[i], confirmed);
        }
        
        for(ll i = n-1; i>=0; i--){
            if(op == k) break;
            diff[i] = max(diff[i]-1, 0ll);
            op++;
        }
        
        ll res = 0;
        for(ll i = n-1; i>=0; i--){
            //cout << diff[i] << " ";
            res += diff[i]*diff[i];
        }
        
        return res;
    }
};