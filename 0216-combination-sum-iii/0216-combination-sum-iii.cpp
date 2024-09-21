class Solution {
public:
    void recur(int i, int k , int n, vector<int>&ds, vector<vector<int>>&ans, int curr_sum){
        if(k < 0) return;
        if(k == 0){
            if(curr_sum == n){
                ans.push_back(ds);
            }
            return;
        }
        if(i > 9) return;

        ds.push_back(i);
        curr_sum += i;
        recur(i+1, k-1, n, ds, ans, curr_sum);
        ds.pop_back();
        curr_sum -= i;
        recur(i+1, k, n, ds, ans, curr_sum);

    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ds;
        vector<vector<int>> ans;
        recur(1, k, n, ds, ans, 0);
        return ans;
    }
};