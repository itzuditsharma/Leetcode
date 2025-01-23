class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0]!=0 || grid[n-1][m-1]!=0){
            return -1;
        }
         if(grid[0][0]==0 && n==1 && m==1){
            return 1;
        }

        vector<vector<int>> dist(n, vector<int>(m, 1e7));
        dist[0][0] = 0;

        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});

        int drow[] = {-1, 0, 1, 0, 1, -1, 1, -1};
        int dcol[] = {0, 1, 0, -1, 1, 1, -1, -1};

        while(!q.empty()){
            auto it = q.front();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;
            q.pop();

            for(int i = 0; i < 8; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && grid[nrow][ncol] == 0 && dist[nrow][ncol] > dis + 1){
                    dist[nrow][ncol] = dis + 1;
                    if(nrow == n-1 && ncol == m-1) return dis + 1;

                    q.push({dis+1, {nrow, ncol}});
                }
            }

        }
        return -1;
    }
};