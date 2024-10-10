class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        vector<int> st;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0) st.push_back(nums[i]);
            else{
                while(st.size()!=0 && abs(nums[i]) > st.back() && st.back() > 0){
                    st.pop_back();
                }

                if(st.size()!=0 && st.back() == abs(nums[i])){
                    st.pop_back();
                }else if(st.size() ==0 || st.back() < 0){
                    st.push_back(nums[i]);
                }
            }
        }

        
        return st;
    }
};