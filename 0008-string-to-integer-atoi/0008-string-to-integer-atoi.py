class Solution:
    def myAtoi(self, s: str) -> int:
        INT_MIN = -2**31
        INT_MAX = 2**31 - 1
        n = len(s)
        i = 0
        while i < n and s[i] == ' ':
            i+=1
        if i == n:
            return 0
        sign = 1
        if s[i] == '-':
            sign = -1
        if s[i] == '-' or s[i] == '+':
            i = i + 1
        num = 0
        while i < len(s):
            if s[i].isdigit() == False:
                break
            digit = int(s[i])
            num = num * 10 + digit
            if sign == 1 and num > INT_MAX:
                return INT_MAX
            if sign == -1 and num * -1 < INT_MIN:
                return INT_MIN
            i+=1
        return int(num * sign)

            