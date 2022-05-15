class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        int ans = 0;
        int n = tiles.size();
        sort(tiles.begin(), tiles.end());
        int left = 0;
        int right = 0;
        int cover = 0;
        
        while(right < n){
            if(tiles[left][0]+carpetLen-1 >= tiles[right][1]){
                cover += tiles[right][1]-tiles[right][0]+1;
                ans = max(ans, cover);
                right++;
            }else{
                ans = max(ans, cover+max(0, tiles[left][0]+carpetLen-tiles[right][0])); 
                cover -= tiles[left][1]-tiles[left][0]+1;
                left++;
            }
        }
        
        return ans;
    }
};