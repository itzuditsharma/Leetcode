class Solution {
public:

    int largestRectangleArea(vector<int>& nums) {
        stack<int> st;
        int maxx = 0;

        for(int i = 0;i < nums.size(); i++){
            while(!st.empty() && nums[st.top()] > nums[i]){
                int element = nums[st.top()];
                st.pop();
                int pse = (st.empty())? -1 : st.top();
                int nse = i;

                maxx = max(maxx, element *(nse - pse - 1));
            }
            st.push(i);
        }

        while(!st.empty()){
            int element = nums[st.top()];
            st.pop();
            int nse = nums.size();
            int pse = (st.empty())? -1 : st.top();

            maxx = max(maxx, element * (nse - pse - 1));
        }
        return maxx;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxiarea = 0;
        vector<vector<int>> presum(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (matrix[i][j] == '1') {
                    sum += 1;
                } else {
                    sum = 0;
                }
                presum[i][j] = sum;
            }
        }

        for (int i = 0; i < n; i++) {
            maxiarea = max(maxiarea, largestRectangleArea(presum[i]));
        }

        return maxiarea;
    }
};