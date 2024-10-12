class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        stack<int> st;
        int maxx = 0;

        for(int i = 0;i < nums.size(); i++){
            while(!st.empty() && nums[st.top()] > nums[i]){
                int element = nums[st.top()];
                st.pop();
                int pse = (st.empty()) ? -1 : st.top();
                int nse =i;

                maxx = max(maxx, element * (nse - pse - 1));
            }
            st.push(i);
        }

        while(!st.empty()){
            int element = nums[st.top()];
            st.pop();
            int pse = (st.empty()) ? -1 : st.top();
            int nse = nums.size();

            maxx = max(maxx, element * (nse - pse - 1));
        }
        return maxx;
    }
};