class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial_color = image[sr][sc];
        queue<pair<int, int>> q;
        q.push({sr, sc});
        vector<vector<int>> new_image = image;
        new_image[sr][sc] = color;
        int n = image.size();
        int m = image[0].size();

        int drow[]  = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >=0 && nrow < n && ncol >=0 && ncol < m && new_image[nrow][ncol] != color && image[nrow][ncol] == initial_color){
                    new_image[nrow][ncol] = color;
                    q.push({nrow, ncol});
                }
            }
        }
        return new_image;
    }
};