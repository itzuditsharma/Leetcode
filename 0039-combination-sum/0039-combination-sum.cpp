class Solution {
public:
    void recur(int i, vector<int>& arr, int target, vector<int> &ds, vector<vector<int>> &ans, int n){
        if(i == n){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }

        if(arr[i] <= target){
            ds.push_back(arr[i]);
            recur(i, arr, target - arr[i], ds, ans, n);
            ds.pop_back();
        }
        recur(i+1, arr, target, ds, ans, n);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = candidates.size();
        recur(0,candidates, target, ds, ans, n);
        return ans;
    }
};