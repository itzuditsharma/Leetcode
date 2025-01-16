class Solution {
public:
    void dfs(int row, int col, int initial_color, vector<vector<int>>& image, vector<vector<int>>& new_image, int color, int d_row[], int d_col[]){
        new_image[row][col] = color;
        int n = image.size();
        int m = image[0].size();

        for(int i = 0; i < 4; i++){
            int nrow = row + d_row[i];
            int ncol = col + d_col[i];

            if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && image[nrow][ncol] == initial_color && new_image[nrow][ncol] != color){
                dfs(nrow, ncol, initial_color, image, new_image,color, d_row, d_col);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial_color = image[sr][sc];
        vector<vector<int>> new_image = image;
        int delta_row[] = {-1, 0, +1, 0};
        int delta_col[] = {0, +1, 0, -1};
        dfs(sr, sc, initial_color, image, new_image, color, delta_row, delta_col);
        return new_image;
    }
};