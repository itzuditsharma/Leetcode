class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int maxsum = 0;
        int lsum = 0;
        int rsum = 0;
        int n = cardPoints.size();
        for(int i = 0; i < k; i++){
            lsum += cardPoints[i];
        }
        maxsum = lsum;
        
        int r_index = n-1;
        for(int i = k-1; i >=0; i--){
            lsum = lsum - cardPoints[i];
            rsum = rsum + cardPoints[r_index];
            maxsum = max(maxsum, lsum+rsum);
            r_index--;
        }
        return maxsum;
    }
};