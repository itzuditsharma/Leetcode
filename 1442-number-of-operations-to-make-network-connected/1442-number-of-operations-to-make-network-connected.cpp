class DisjointSet{
    public:
    vector<int> size, parent;
        DisjointSet(int n){
            size.resize(n+1);
            parent.resize(n+1);
            for(int i = 0; i < n; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findUpar(int node){
            if(parent[node] == node){
                return node;
            }

            return parent[node] = findUpar(parent[node]);
        }

        void UnionBySize(int u, int v){
            int ulp_u = findUpar(u);
            int ulp_v = findUpar(v);
            if(ulp_u == ulp_v) return;

            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int extras = 0;
        DisjointSet ds(n);
        for(auto it : connections){
            int u = it[0];
            int v = it[1];

            if(ds.findUpar(u) == ds.findUpar(v)){
                extras++;
            }else{
                ds.UnionBySize(u, v);
            }
        }

        int components = 0;
        for(int i = 0; i < n; i++){
            if(ds.parent[i] == i) components++;
        }

        int ans =  components - 1; 
        if(extras >= ans){
            return ans;
        }
        return -1;
    }
};