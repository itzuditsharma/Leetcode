class Solution {
public:
    void dfs(int node,vector<int> adjls[],vector<int>& vist){
       vist[node]=1;
       for(auto it : adjls[node]){
            if(!vist[it]){
                dfs(it,adjls,vist);
            }
       }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adjls[n];
        //change matrix to adjlist 
        for (int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }

        
      vector<int> vist;
      for(int i=0;i<n;i++){
          vist.push_back(0);
      }
       //int vist[n]= {0};
         int cnt = 0;
        for(int i=0;i<n;i++){
            if(!vist[i]){
                cnt++;
                dfs(i,adjls,vist);
            }
        }
        return cnt;
    }
  
};