class Solution {
public:
    void dfs(int row, int col, int initial_color, int color, vector<vector<int>>& image,  vector<vector<int>> &new_image, int drow[], int dcol[]){
        image[row][col] = color;

        int n = image.size();
        int m = image[0].size();

        for(int i = 0;i < 4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >=0 & nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == initial_color && new_image[nrow][ncol] != color){
                dfs(nrow, ncol, initial_color, color, image, new_image, drow, dcol);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial_color = image[sr][sc];
        vector<vector<int>> new_image = image;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        dfs(sr, sc, initial_color, color, image, new_image, drow, dcol);
        return image;
    }
};