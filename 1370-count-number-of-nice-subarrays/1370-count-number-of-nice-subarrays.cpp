class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(n);
        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 0){
                temp[i] = 0;
            }else{
                temp[i] = 1;
            }
        }
        int sum = 0;
        int count = 0;
        unordered_map<int, int> mapp;
        mapp[0] = 1;
        for(int i = 0; i < n; i++){
            sum += temp[i];
            int remain = sum - k;
            if(mapp.find(remain) != mapp.end()){
                count += mapp[remain];
            }
            mapp[sum]++;
        }
        return count;
    }
};