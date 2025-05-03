class Solution {
public:
    vector<int> fillValues(int rows){
        int ans = 1;
        vector<int> temp;
        temp.push_back(1);

        for(int i = 1; i < rows; i++){
            ans = ans * (rows - i);
            ans = ans / i;
            temp.push_back(ans);
        }
        return temp;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 1; i <= numRows; i++){
            ans.push_back(fillValues(i));
        }
        return ans;
    }
};