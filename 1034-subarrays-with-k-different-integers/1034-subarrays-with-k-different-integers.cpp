class Solution {
public:
    int helper(vector<int>& nums, int k){
        int i = 0;
        int j = 0;
        int count = 0;
        unordered_map<int, int> mapp;
        while(j < nums.size()){
            mapp[nums[j]]++;
            while(mapp.size() > k){
                mapp[nums[i]]--;
                if(mapp[nums[i]] == 0)mapp.erase(nums[i]);
                i++;
            }
            count += (j-i+1);
            j++;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k-1);
    }
};