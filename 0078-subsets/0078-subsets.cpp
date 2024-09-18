class Solution {
public:
    void recur_subsets(int i, vector<int>& nums, vector<int>& ds, vector<vector<int>> &ans, int n){
        if(i == n){
            ans.push_back(ds);
            return;
        }

        ds.push_back(nums[i]);
        recur_subsets(i+1, nums, ds, ans, n);
        ds.pop_back();

        recur_subsets(i+1, nums, ds, ans, n);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = nums.size();
        recur_subsets(0, nums, ds, ans, n);
        return ans;
    }
};