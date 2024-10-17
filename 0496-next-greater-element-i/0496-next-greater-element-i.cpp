class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2 = nums2.size();
        unordered_map<int, int> mapp;
        stack<int> st;

        mapp[nums2[n2-1]] = -1;
        st.push(nums2[n2-1]);

        for(int i = n2-2; i >=0; i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }

            if(st.empty()){
                mapp[nums2[i]] = -1;
            }else{
                mapp[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }

        vector<int> ans;
        for(int i = 0; i < nums1.size(); i++){
            ans.push_back(mapp[nums1[i]]);
        }

        return ans;
    }
};