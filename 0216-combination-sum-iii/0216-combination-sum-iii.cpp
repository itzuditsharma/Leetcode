class Solution {
public:
    void recur(int i, int k , int n, vector<int>&ds, vector<vector<int>>&ans){
        if(k < 0) return;
        if(k == 0){
            if(n == 0){
                ans.push_back(ds);
            }
            return;
        }
        if(i > 9) return;

        ds.push_back(i);
        recur(i+1, k-1, n-i, ds, ans);
        ds.pop_back();
        recur(i+1, k, n, ds, ans);

    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ds;
        vector<vector<int>> ans;
        recur(1, k, n, ds, ans);
        return ans;
    }
};