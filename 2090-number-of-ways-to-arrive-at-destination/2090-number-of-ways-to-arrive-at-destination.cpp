class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<long long, long long>,
        vector<pair<long long, long long>>,
        greater<pair<long long, long long>>> pq;

        pq.push({0,0});  //dist, node

        vector<int> dist(n, 1e9);
        dist[0] = 1;
        vector<int> ways(n, 0);
        ways[0] = 1;

        int mod = 1e9 + 7;

        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]){
                int adjNode = it.first;
                int edw = it.second;

                if(edw + dis < dist[adjNode]){
                    dist[adjNode] = edw + dis;
                    pq.push({edw+dis, adjNode});
                    ways[adjNode] = ways[node];
                }else if(edw + dis == dist[adjNode]){
                    dist[adjNode] = edw + dis;
                    ways[adjNode] = (ways[node] + ways[adjNode]) % mod;
                }
            }
        }
        return ways[n-1]%mod;
    }   
};