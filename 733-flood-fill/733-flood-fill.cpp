class Solution {
public:
    
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    
    void fill(vector<vector<int>>& image, vector<vector<int>>& newImage, int sr, int sc, int newColor, int i, int j){
        if(i == -1 || j== -1 || i==image.size() || j==image[0].size() || image[i][j] != image[sr][sc] || newImage[i][j] == newColor) return;
        
        newImage[i][j] = newColor;
        
        for(int d= 0; d<4; d++){
            int ni = i+dx[d], nj = j + dy[d];
            fill(image, newImage, sr, sc, newColor, ni, nj);
        }
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        vector<vector<int>> newImage(image);
        
        fill(image, newImage, sr, sc, newColor, sr, sc);
        
        
        
        return newImage;
    }
};