class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """

        words = s.split()
        stack = []

        for i in words:
            stack.append(i)

        rev_words = []
        while stack:
            rev_words.append(stack.pop())
        
        ans = ' '.join(rev_words)
        
        return ans
        