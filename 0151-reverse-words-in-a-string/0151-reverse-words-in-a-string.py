class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        
        temp = ""
        ans = ""

        for i in range(len(s)):
            ch = s[i]

            if ch!=" ":
                temp += ch
            else:
                if ans != "":
                    ans = temp + ("" if temp == "" else " ") + ans
                else:
                    ans = temp
                temp = ""

        if temp != "":
            if ans != "":
                ans = temp + " " + ans
            else:
                ans = temp
        return ans
