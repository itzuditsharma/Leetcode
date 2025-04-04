class Solution {
public:
    bool bfs(int node, int color, vector<vector<int>>& graph, vector<int> &colors){
        colors[node] = color;
        for(auto it : graph[node]){
            if(colors[it] == -1){
                if(bfs(it, !color, graph, colors) == false) return false;
            }else if(colors[it] == color){
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);

        for(int i = 0; i < n; i++){
            if(colors[i] == -1){
                if(bfs(i, 0, graph, colors) == false) return false;
            }
        }
        return true;
    }
};