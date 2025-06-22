class DisjointSet{
    public:
    vector<int> parent, size;
    DisjointSet(int n){
        size.resize(n+1);
        parent.resize(n+1);

        for(int i = 0; i < n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node){
        if(parent[node] == node){
            return node;
        }

        return parent[node] = findUPar(parent[node]);
    }

    void UnionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
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
        DisjointSet ds(n);
        int extras = 0;
        for(auto it : connections){
            int u = it[0];
            int v = it[1];

            if(ds.findUPar(u) == ds.findUPar(v)){
                extras++;
            }else{
                ds.UnionBySize(u,v);
            }
        }

        int components = 0;
        for(int i = 0;i < n; i++){
            if(ds.parent[i] == i) components++;
        }

        int ans = components -1;
        if(extras >= ans) return ans;
        return -1;
    }
};