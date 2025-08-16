class Solution(object):
    def reverseWords(self, s):
        temp_string =  (" ".join(s.split()[::-1])).strip()
        return temp_string

        