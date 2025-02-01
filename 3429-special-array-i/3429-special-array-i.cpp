class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 1; i++){
            int currNumber = nums[i];
            int adjNumber = nums[i+1];

            if(currNumber % 2 == 0 && adjNumber %2 == 0){
                return false;
            }else if(currNumber % 2 == 1 && adjNumber % 2 == 1){
                return false;
            }
        }
        return true;
    }
};