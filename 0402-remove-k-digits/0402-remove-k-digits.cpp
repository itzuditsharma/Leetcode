class Solution {
public:
    string removeKdigits(string nums, int k) {
        stack<char> st;
        for(int i = 0; i < nums.length(); i++){
            while(!st.empty() && k > 0 && nums[i] - '0' < st.top()-'0'){
                st.pop();
                k--;
            }
            st.push(nums[i]);
        }

        while(k > 0){
            st.pop();
            k--;
        }

        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        
        while(res.size() && res.back() == '0'){
            res.pop_back();
        }

        reverse(res.begin(), res.end());
        if(res.size() == 0) return "0";
        return res;

    }
};