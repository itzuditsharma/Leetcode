class Solution {
public:

    bool dfs(int node, int color, vector<int> &colors, vector<vector<int>>& graph){
        colors[node] = color;

        for(auto it : graph[node]){
            if(colors[it] == -1){
                if(dfs(it, !color, colors, graph) == false) return false;
            }else if(colors[it] == color){
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = graph[0].size();

        vector<int> colors(n, -1);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(colors[i] == -1){
                    if(dfs(i, 0, colors, graph) == true) return true;
                }
            }
        }
        return false;
    }
};