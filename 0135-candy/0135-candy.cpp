class Solution {
public:
    // Slope method - Most optimal
    int candy(vector<int>& ratings) {
        int i = 1;
        int n = ratings.size();
        int sum = 1;
        while(i < n){
            if(ratings[i] == ratings[i-1]){
                sum += 1;
                i++;
                continue;
            }
            int peak = 1;
            while(i < n && ratings[i] > ratings[i-1]){
                peak += 1;
                sum += peak;
                i++; 
            }

            int down = 1;
            while(i < n && ratings[i] < ratings[i-1]){
                sum += down;
                down++;
                i++;
            }

            if(down > peak){
                sum += (down - peak);
            }  
        }
        return sum;
    }
};