class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mapp;
        mapp[0] = 1;
        int sum = 0;
        int count = 0;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int remain = sum - goal;
            if(mapp.find(remain) != mapp.end()){
                count+= mapp[remain];
            }
            mapp[sum]++;
        }
        return count;
    }
};