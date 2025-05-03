class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        int count = 0;
        unordered_set<int> sett;

        for(int i = 0; i < nums.size(); i++){
            sett.insert(nums[i]);
        }
        int x;
        for(auto it : sett){
            if(sett.find(it - 1) == sett.end()){
                count = 1;
                x = it;

                while(sett.find(x + 1) != sett.end()){
                    x = x + 1;
                    count++;
                }
            }
            longest = max(longest, count);
        }
        return longest;
    }
};