class Solution {
public:
    void recur(int i, vector<int>& arr, int target, vector<int>&ds, vector<vector<int>> &ans){
        if(i == arr.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }

        if(arr[i] <= target){
            ds.push_back(arr[i]);
            recur(i, arr, target - arr[i], ds, ans);
            ds.pop_back();
        }

        recur(i+1, arr, target, ds, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int i = 0;
        recur(i, candidates, target, ds, ans);
        return ans;
    }
};