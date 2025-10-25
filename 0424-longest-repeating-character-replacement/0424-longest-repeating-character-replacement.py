class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        n = len(s)
        i = 0
        j = 0
        maxlen = 0
        maxfeq = 0
        hash_array = [0] * 26

        while j < n:    
            hash_array[ord(s[j]) - ord('A')] += 1
            maxfeq = max(hash_array)

            while (j-i+1) - maxfeq > k:
                hash_array[ord(s[i]) - ord('A')] -= 1
                i+=1
                maxfeq = max(hash_array)

            maxlen = max(maxlen, j-i+1)
            j+=1
        
        return maxlen
