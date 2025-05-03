class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mapp;
        int sum = 0;
        int count = 0;
        mapp[0] = 1;

        for(int i = 0;i < nums.size(); i++){
            sum += nums[i];
            int remain = sum - k;
            if(mapp.find(remain) != mapp.end()){
                count+=mapp[remain];
            }
            mapp[sum]++;
        }
        return count;
    }
};