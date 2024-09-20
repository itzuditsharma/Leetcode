class Solution {
public:

    void recur(int ind, vector<int>& arr, int target, vector<int>&ds, vector<vector<int>>&ans){

        if(target == 0){
            ans.push_back(ds);
            return;
        }

        for(int i = ind; i < arr.size(); i++){
            if(i > ind && arr[i] == arr[i-1])continue;
            if(arr[i] > target) break;
            ds.push_back(arr[i]);
            recur(i+1, arr, target-arr[i], ds, ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> ds;
        vector<vector<int>> ans;
        int i = 0;
        recur(i, candidates, target, ds, ans);
        return ans;
    }
};