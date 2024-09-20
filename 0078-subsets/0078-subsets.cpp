class Solution {
public:

    void recur(int i, vector<int>arr, vector<vector<int>> &ans, vector<int>&ds){
        if(i == arr.size()){
            ans.push_back(ds);
            return;
        }

        ds.push_back(arr[i]);
        recur(i+1, arr, ans, ds);
        ds.pop_back();

        recur(i+1, arr, ans, ds);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int i = 0;
        recur(i, nums, ans, ds);
        return ans;
    }
};