class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> hash(n);
        int maxlen = 0;
        int last_index = 0;
        for(int i = 0; i < n; i++) hash[i] = i;

        for(int i = 0; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[i] % nums[prev] == 0 && 1+dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if(maxlen < dp[i]){
                maxlen = dp[i];
                last_index = i;
            }
        }

        vector<int> temp;
        temp.push_back(nums[last_index]);
        while(hash[last_index] != last_index){
            last_index = hash[last_index];
            temp.push_back(nums[last_index]);
        }
        return temp;
    }
};