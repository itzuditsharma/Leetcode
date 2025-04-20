class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;
        // {diff, {row, col}}
        pq.push({0, {0,0}});

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!pq.empty()){
            auto it = pq.top();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            pq.pop();

            if(row == n-1 && col == m-1) return diff;

            for(int i = 0; i < 4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >=0 && nrow < n && ncol >=0 && ncol < m){
                    int newDiff = max(diff, heights[nrow][ncol] - heights[row][col]);
                    if(newDiff < dist[nrow][ncol]){
                        dist[nrow][ncol]=newDiff;
                        pq.push({newDiff, {nrow, ncol}});
                    }
                }
            }
        }

        return -1;
        
    }
};