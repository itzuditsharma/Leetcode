class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int> st;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0) st.push(nums[i]);
            else{
                while(!st.empty() && abs(nums[i]) > st.top() && st.top() > 0){
                    st.pop();
                }

                if(!st.empty() && st.top() == abs(nums[i])){
                    st.pop();
                }else if(st.empty() || st.top() < 0){
                    st.push(nums[i]);
                }
            }
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};