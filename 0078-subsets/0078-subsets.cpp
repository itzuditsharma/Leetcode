class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        int nosubsets = 1 << n;  //2^n
        for(int num = 0; num < nosubsets; num++){
            vector<int> ds;
            for(int i = 0;i < n; i++){
                // check if ith bit is set or not
                if(num & (1 << i)){
                    ds.push_back(nums[i]);
                }
            }
            ans.push_back(ds);
        }

        return ans;
    }
};