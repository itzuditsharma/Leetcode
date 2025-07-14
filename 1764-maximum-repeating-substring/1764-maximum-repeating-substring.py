class Solution(object):
    def maxRepeating(self, sequence, word):
        """
        :type sequence: str
        :type word: str
        :rtype: int
        """
        if sequence == word:
            return 1

        max_repeats = 0
        i = 0
        len_s = len(word)

        while i <= len(sequence) - len_s:
            count = 0
            while sequence[i + count * len_s : i + (count + 1) * len_s] == word:
                count += 1

            max_repeats = max(max_repeats, count)
            i+= 1
        
        return max_repeats

        