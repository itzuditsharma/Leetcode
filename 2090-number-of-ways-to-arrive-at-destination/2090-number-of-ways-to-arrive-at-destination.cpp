class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        int mod = (1e9 + 7);
        // dis, node 
        priority_queue<pair<long long, long long>,
        vector<pair<long long, long long>>,
        greater<pair<long long, long long>>> pq;

        pq.push({0,0});
        vector<long long int> dist(n, 1e9);
        vector<long long int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;

        while(!pq.empty()){
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]){
                int adjNode = it.first;
                long long edw = it.second;

                if(dist[adjNode] > edw + dis){
                    dist[adjNode] = edw + dis;
                    pq.push({edw + dis, adjNode});
                    ways[adjNode] = ways[node];
                }else if(dist[adjNode] == edw + dis){
                    dist[adjNode] = edw + dis;
                    ways[adjNode] = ways[node] + ways[adjNode];
                }
            }
        }
        return ways[n-1] % mod;
    }
};