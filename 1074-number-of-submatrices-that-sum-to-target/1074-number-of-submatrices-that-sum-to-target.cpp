class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
      /*Step-1. First calc prefRowSum for each row in the matrix. matrix[r][c2] - matrix[r][c1-1] indicates sum of matrix[r][c1....c2].
        Step-2. Iterate over all possible column combinations using c1 and c2. 
        Step-3. For each particular c1, c2 combination, Iterate over all the rows and calculate prefSum of submatrices [{0, c1} and {r, c2}].
                Also maintain a frequency map of prefMatrixSum. and use it to calculate no. of 2-D or 1-D submatrices in starting at c1 and ending                 at c2 with sum = target. 
        Step-4. PrefMatrixSum[r] denotes sum [{0, c1} and {r, c2}]. PrefMatrixSum[r] - prefMatrixSum[l-1] denotes sum [{l, c1} and {r, c2}].
                Hence we can easily obtain submatrices starting at c1 and ending at c2. PrefMatrixSum[r] = PrefMatrixSum[r-1]+prefRowSum[r].
        Step-5. Using these facts calculate for each possible c1, c2 combinations, no. of submatrices(with c1, c2 same and only rows different)                     with sum = target.*/
        
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
            }
        }
        
        return res;
    }
    //T - O(m*m*n)
    //S - O(n)
};