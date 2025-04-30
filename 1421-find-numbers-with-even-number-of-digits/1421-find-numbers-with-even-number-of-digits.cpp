class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            int val = nums[i];
            int temp_count = 0;
            while(val != 0){
                val /= 10;
                temp_count++;
            }

            if(temp_count % 2 == 0) count++;
        }
        return count;
    }
};