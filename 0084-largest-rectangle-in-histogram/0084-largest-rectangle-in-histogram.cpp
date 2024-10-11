class Solution {
public:
    vector<int>NSL(vector<int> nums){
        vector<int> ans(nums.size());
        stack<int> st;

        for(int i = 0; i < nums.size();i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }

            if(st.empty()){
                ans[i] = -1;
            }else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int>NSR(vector<int> nums){
        vector<int> ans(nums.size());
        stack<int> st;

        for(int i = nums.size()-1; i >=0 ;i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }

            if(st.empty()){
                ans[i] = nums.size();
            }else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> nsl = NSL(heights);
        vector<int> nsr = NSR(heights);


        int maxx = 0;
        for(int i = 0; i < heights.size(); i++){
            int l = nsl[i];
            int r = nsr[i];
            maxx = max(maxx, heights[i] * (r-l-1));
        }
        return maxx;    
        
    }
};