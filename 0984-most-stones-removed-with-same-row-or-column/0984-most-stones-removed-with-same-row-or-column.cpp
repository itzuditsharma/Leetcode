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
            if(node == parent[node]){
                return node;
            }

            return parent[node] = findUPar(parent[node]);
        }

        void UnionBySize(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if(ulp_u == ulp_v) return;

            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u]=ulp_v;
                size[ulp_v] += size[ulp_u];
            }else{
                parent[ulp_v]=ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxrow = 0;
        int maxcol = 0;

        for(auto it : stones){
            maxrow = max(maxrow, it[0]);
            maxcol = max(maxcol, it[1]);
        }

        DisjointSet ds(maxrow+maxcol+1);

        for(auto it : stones){
            int nodeRow = it[0];
            int nodeCol = it[1] + maxcol + 1;
            ds.UnionBySize(nodeRow, nodeCol);
        }

        int components = 0;
        for(int i=0; i < maxrow+maxcol+1; i++){
            if(ds.parent[i] == i && ds.size[i] > 1) components++;
        }
        return n-components;
    }
};