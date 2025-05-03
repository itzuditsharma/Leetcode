class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        vector<int> temp_interval;
        temp_interval = intervals[0];

        for(auto it : intervals){
            if(it[0] <= temp_interval[1]){
                temp_interval[1] = max(temp_interval[1], it[1]);
            }else{
                ans.push_back(temp_interval);
                temp_interval = it;
            }
        }
        ans.push_back(temp_interval);
        return ans;
    }
};