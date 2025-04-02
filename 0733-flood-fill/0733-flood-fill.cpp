class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& image, int ini_color, int color, vector<vector<int>> &new_image, int n, int m, int drow[], int dcol[]){
        new_image[row][col] = color;

        for(int i = 0; i < 4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >=0 && nrow < n && ncol >=0 && ncol < m && image[nrow][ncol] == ini_color && new_image[nrow][ncol] != color){
                dfs(nrow, ncol, image, ini_color, color, new_image, n, m, drow, dcol);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ini_color = image[sr][sc];
        vector<vector<int>> new_image = image;
        int n = image.size();
        int m = image[0].size();
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        dfs(sr, sc, image,ini_color, color, new_image, n, m, drow, dcol);
        return new_image;
    }
};