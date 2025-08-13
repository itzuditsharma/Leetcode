class Solution(object):
    def reverseWords(self, s):
        words = s.split()
        stack = []

        for word in words:
            stack.append(word)

        rev_words = []
        while stack:
            rev_words.append(stack.pop())

        return " ".join(rev_words)

        
        