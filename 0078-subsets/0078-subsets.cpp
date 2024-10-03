class Solution {
public:
    void recur(int i, vector<vector<int>> &ans, vector<int> &ds, vector<int>& nums){
        if(i == nums.size()){
            ans.push_back(ds);
            return;
        }

        ds.push_back(nums[i]);
        recur(i+1, ans, ds, nums);
        ds.pop_back();

        recur(i+1, ans, ds, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        recur(0, ans, ds, nums);
        return ans;
    }
};