class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        // {node, edW} -> Edge weight
        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        // {stops, {node, distance}}
        queue<pair<int, pair<int, int>>>q;
        q.push({0, {src,0}});

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            for(auto it : adj[node]){
                int adjNode = it.first;
                int edW = it.second;

                if(dist[adjNode] > edW + cost && stops <= k){
                    dist[adjNode] = edW + cost;
                    q.push({stops+1, {adjNode, edW + cost}});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};