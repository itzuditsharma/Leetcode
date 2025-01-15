class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int key = image[sr][sc];
        image[sr][sc] = color;

        queue<pair<int, int>> q;
        // vector<vector<int>> vis(n,vector<int>(m,0));
        int vis[n][m];
        for(int i = 0;i < n; i++){
            for(int j = 0; j < m; j++){
                vis[i][j] = 0;
            }
        }
        q.push({sr, sc});

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >=0 && nrow < n && ncol >=0 && ncol < m && image[nrow][ncol] == key && vis[nrow][ncol] != 1){
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                    image[nrow][ncol] = color;
                }
            }
        }

        return image;
    }
};