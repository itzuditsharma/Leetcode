class Solution {
public:
    void dfs(int node, vector<int> adjls[], vector<int>& vis){
        vis[node] = 1;
        for(auto it : adjls[node]){
            if(!vis[it]){
                dfs(it, adjls, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adjls[n];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }

        vector<int> vis;
        for(int i = 0; i < n; i++){
            vis.push_back(0);
        }

        int count = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                count++;
                dfs(i, adjls, vis);
            }
        }
        return count;
    }
};