class Solution {
public:
    
    static bool cmp(vector<int> &a, vector<int>&b)
    {
        if(a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
      /*
        Approach: Used segment tree.
        Finding the leftmost index with > k free seats in [0...leftMostIndex]
        Which means [0...leftMostIndex-1] have exactly k free seats
        There is no valid ans for [[5,1], [5,1]] or [[6,1], [7,0], [5,2], [5,2]]*/
        int n = people.size();
        sort(people.begin(), people.end(), cmp);
        
        vector<vector<int>> res(n);
        
        for(int i=0; i<n; i++){
            int h = people[i][0], k = people[i][1];
            int cnt = 0;
            int j;
            for(j=0; j<n; j++){
                
                if(res[j].size() == 0) cnt++;
                if(cnt == k+1) break;
            }
            res[j] = people[i];
        }
        
        return res;
    }
    //T - O(n*n)
    //S - O(n)
};