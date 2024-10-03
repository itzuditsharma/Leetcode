class Solution {
public:
    int minBitFlips(int start, int goal) {
        int n = start ^ goal;
        
        int count = 0;
        // Check count number of set bits in notebook 
        while(n != 0){
            n = n & (n-1);
            count++;
        }

        return count;
    }
};