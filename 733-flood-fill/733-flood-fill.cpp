class Solution {
public:
    
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    
    void fill(vector<vector<int>>& image, int i, int j, int& newColor, int &startColor){
        if(i == -1 || j== -1 || i==image.size() || j==image[0].size() || image[i][j] != startColor || image[i][j] == newColor) return;
        
        image[i][j] = newColor;
        
        for(int d= 0; d<4; d++){
            int ni = i+dx[d], nj = j + dy[d];
            fill(image, ni, nj, newColor, startColor);
        }
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        //Read the question properly
        //Only 4 directions of those pixels are consider which have painted by me and not by default.
        //case 1 : startColor 2 and newColor 2(Corner case, but no need to color in this case)
        //case 2 : startColor 1 and newColor 2 with only 1's (Normal case)
        //Case 3 : startColor 1 and newColor 2 with some 1's ans some 2's (Corner case)
        //In case 3, as 2 are already colored and as they are different from start color, i will not be painting those 2's. Hence no need to paint their(already colored 2) neighbours.
        int startColor = image[sr][sc];
        fill(image, sr, sc, newColor, startColor);

        return image;
    }
    //T - O(m*n)
    //S - O(1)
};