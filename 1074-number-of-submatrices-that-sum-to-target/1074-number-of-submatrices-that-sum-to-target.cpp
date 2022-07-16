class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        for(int r=0; r<n; r++){
            for(int c=1; c<m; c++){
                matrix[r][c] += matrix[r][c-1];
            }
        }
        
        int res = 0;
        for(int c1=0; c1<m; c1++){
            for(int c2=c1; c2<m; c2++){
                int sum = 0;
                unordered_map<int, int> freq;
                freq[0]++;
                for(int r=0; r<n; r++){
                    sum += matrix[r][c2] -((c1>0)?matrix[r][c1-1]:0);
                    res += freq[sum-target];
                    freq[sum]++;
                }
                //cout << c1 << " " << c2 << " " << sum << endl;
            }
        }
        
        return res;
    }
};