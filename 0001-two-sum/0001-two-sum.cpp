class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() -1;
        vector<pair<int, int>> pairs;

        for(int i = 0; i < nums.size(); i++){
            pairs.push_back({nums[i], i});
        }

        sort(pairs.begin(), pairs.end());

        while(i < j){
            int sum = pairs[i].first + pairs[j].first;
            if(sum == target){
                return {pairs[i].second, pairs[j].second};
            }else if(sum > target){
                j--;
            }else{
                i++;
            }

        }
        return {};
    }
};