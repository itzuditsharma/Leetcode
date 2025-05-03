class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.empty() == true) return 0;
        // 1,2,3,4,100,200
        int longest = 1;
        int count = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1] == nums[i]){
                continue;
            }else if(nums[i-1] + 1 == nums[i]){
                count++;
            }else{
                longest = max(longest, count);
                count = 1;
            }
        }
        return max(longest, count);
    }
};