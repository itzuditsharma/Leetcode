class DisjointSet{
    public:
    vector<int> size, parent;
    
    DisjointSet(int n){
        size.resize(n+1);
        parent.resize(n+1);
        for(int i = 0; i < n; i++){
            size[i] = 1;
            parent[i] = i;
        }
    }

    int findUParent(int node){
        if(node == parent[node]) return node;

        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

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

            if(ds.findUParent(u) == ds.findUParent(v)){
                extras++;
            }else{
                ds.unionBySize(u,v);
            }
        }

        int noComponents = 0;
        for(int  i= 0;  i < n; i++){
            if(ds.parent[i] == i) noComponents++;
        }

        int ans = noComponents - 1;
        if(extras >= ans) return ans;
        return -1;
    }
};