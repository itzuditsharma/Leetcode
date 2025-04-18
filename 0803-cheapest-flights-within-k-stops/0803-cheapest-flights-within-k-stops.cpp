class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        // node -> {adjNode, edgeWeight}
        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        // steps, node, wt 

        while(!q.empty()){
            auto it = q.front();
            int steps = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            q.pop();

            for(auto it : adj[node]){
                int adjNode = it.first;
                int edw = it.second;
                if(dist[adjNode] > edw + cost && steps <=k){
                    dist[adjNode] = edw + cost;
                    q.push({steps+ 1, {adjNode, edw + cost}});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};