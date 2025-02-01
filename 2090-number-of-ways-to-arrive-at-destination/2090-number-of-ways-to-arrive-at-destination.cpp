class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        // node -> {adjNode, edw}
        for(auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // {dist, node}
        priority_queue<pair<long long, long long>, 
        vector<pair<long long, long long>>, 
        greater<pair<long long, long long>>> pq;
        pq.push({0,0});

        vector<long long int> dist(n, 1e18);
        dist[0] = 0;
        vector<long long int> ways(n, 0);
        ways[0] = 1;

        int mod = (1e9 + 7);

        while(!pq.empty()){
            auto it = pq.top();
            long long dis = it.first;
            int node = it.second;
            pq.pop();

            for(auto it : adj[node]){
                int adjNode = it.first;
                long long edw = it.second;

                if(dist[adjNode] > edw + dis){
                    dist[adjNode] = edw + dis;
                    pq.push({edw + dis, adjNode});
                    ways[adjNode] = ways[node];
                }else if(dist[adjNode] == edw + dis){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};