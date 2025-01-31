class DisjointSet{
public: 
    vector<int> size, parent;
    DisjointSet(int n){
        size.resize(n+1);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int findUPar(int node){
        if(parent[node] == node) return node;
        
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionBySize(int u, int v){
        int up_u = findUPar(u);
        int up_v = findUPar(v);
        
        if(up_u == up_v) return;
        
        if(size[up_u] < size[up_v]){
            parent[up_u] = up_v;
            size[up_v] += size[up_u]; 
        }else{
            parent[up_v] = up_u;
            size[up_u] += size[up_v]; 
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);

        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 0) continue;

                int drow[] = {-1, 0, 1, 0};
                int dcol[] = {0, 1, 0, -1};

                for(int i = 0; i < 4; i++){
                    int adjRow = row + drow[i];
                    int adjCol = col + dcol[i];

                    if(adjRow >=0 && adjRow < n && adjCol >=0 && adjCol < n && grid[adjRow][adjCol] == 1){
                        int nodeNo = row * n + col;
                        int adjNodeNo = adjRow * n + adjCol;

                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }

        int mx = 0;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 1) continue;

                int drow[] = {-1, 0, 1, 0};
                int dcol[] = {0, 1, 0, -1};
                set<int> components;
                for(int i = 0; i < 4; i++){
                    int adjRow = row + drow[i];
                    int adjCol = col + dcol[i];

                    if(adjRow >=0 && adjRow < n && adjCol >=0 && adjCol < n){
                        int nodeNo = row * n + col;
                        int adjNodeNo = adjRow * n + adjCol;

                        if(grid[adjRow][adjCol] == 1){
                            components.insert(ds.findUPar(adjNodeNo));
                        }
                    }
                }
                int sum = 0;
                for(auto it : components){
                    sum += ds.size[it];
                }
                sum += 1; //For the 1 inserted 
                mx = max(mx, sum);
            }
        }
        for(int i = 0; i < n*n; i++){
            mx = max(mx, ds.size[ds.findUPar(i)]);
        }
        return mx;
    }
};