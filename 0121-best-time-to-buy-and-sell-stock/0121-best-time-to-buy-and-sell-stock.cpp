class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int j = 0;
        int maxx = INT_MIN;

        while(j < prices.size()){
            int profit = prices[j] - prices[i];
            maxx = max(maxx, profit);
            if(profit < 0){
                i++;
            }else{
                j++;
            }
        }
        return maxx;
    }
};