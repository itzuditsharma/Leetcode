class Solution {
public:
    void helper(int i, int n, vector<int>&nums, vector<int>&ds, vector<vector<int>>&ans){
        if(i == n){
            ans.push_back(ds);
            return;
        }

        ds.push_back(nums[i]);
        helper(i+1, n, nums, ds, ans);
        ds.pop_back();
        helper(i+1, n, nums, ds, ans);
    }   

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> ds;

        helper(0, n, nums, ds, ans);
        return ans;
        
    }
};