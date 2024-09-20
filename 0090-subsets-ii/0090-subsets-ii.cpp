class Solution {
public:

    void recur(int ind, vector<int>& arr, vector<int>&ds, vector<vector<int>> &ans){
        ans.push_back(ds);

        for(int i = ind; i < arr.size(); i++){
            if(i != ind && arr[i] == arr[i-1]) continue;
            ds.push_back(arr[i]);
            recur(i+1, arr, ds, ans);
            ds.pop_back();
        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>> ans;
        int i = 0;
        sort(nums.begin(), nums.end());
        recur(i, nums, ds, ans);
        return ans;
    }
};