class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mapp;
        stack<int> st;

        int n1 = nums1.size();
        int n2 = nums2.size();

        st.push(nums2[n2-1]);
        mapp[nums2[n2-1]] = -1;

        for(int i = n2-2; i>=0; i--){
            while(!st.empty() && nums2[i] >= st.top()){
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
        for(int i = 0; i < n1; i++){
            ans.push_back(mapp[nums1[i]]);
        }

        return ans;
    }
};