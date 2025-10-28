class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        hash_array = [-1, -1, -1]
        count = 0
        for i in range(len(s)):
            hash_array[ord(s[i]) - ord('a')] = i
            if hash_array[0] != -1 and hash_array[1] != -1 and hash_array[2] != -1:
                count += min(hash_array) + 1
        
        return count
