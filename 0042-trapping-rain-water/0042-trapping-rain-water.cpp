class Solution {
public:
    int trap(vector<int>& nums) {
        int leftmax = 0;
        int rightmax = 0;
        int n = nums.size();

        int left = 0;
        int right = n-1;
        int res = 0;

        while(left <= right){
            if(nums[left] <= nums[right]){
                if(nums[left] >= leftmax){
                    leftmax = nums[left];
                }else{
                    res += leftmax - nums[left];
                }
                left++;
            }else{
                if(nums[right] >= rightmax){
                    rightmax = nums[right];
                }else{
                    res += rightmax - nums[right];
                }
                right--;
            }
        }
        return res;
    }
};