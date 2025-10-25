class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        i = 0
        j = 0
        hash_array = [0] * 26
        maxfreq = 0
        maxlen = 0
        n = len(s)

        while j < n:
            hash_array[ord(s[j]) - ord('A')] += 1
            maxfreq = max(maxfreq, hash_array[ord(s[j]) - ord('A')]) 

            while (j-i+1) - maxfreq > k:
                hash_array[ord(s[i]) - ord('A')] -= 1
                i+=1
                maxfreq = max(hash_array)
            
            maxlen = max(maxlen, j-i+1)
            j+=1
        
        return maxlen
