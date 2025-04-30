class Solution {
public:
    int func(vector<int>& nums, int k){
        int i = 0; 
        int j = 0;
        int count= 0;
        unordered_map<int, int> mapp;
        int n = nums.size();

        while(j < n){
            mapp[nums[j]]++;
            while(mapp.size() > k){
                mapp[nums[i]]--;
                if(mapp[nums[i]] == 0) mapp.erase(nums[i]);
                i++;
            }
            count += j-i+1;
            j++;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return func(nums, k) - func(nums, k-1);
    }

};