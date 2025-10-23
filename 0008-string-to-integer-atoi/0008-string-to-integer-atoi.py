class Solution:
    def myAtoi(self, s: str) -> int:

        INT_MAX, INT_MIN = 2**31 - 1, -2**31
        i = 0
        n =len(s)   
        while i < n and s[i] == ' ':
            i+=1
        if i == n:
            return 0
        s = s[i:]
        sign = 1
        if s[0] == '-':
            sign = -1
        i = 1 if s[0] == '+' or s[0] == '-' else 0
        ans = 0

        while i < len(s):
            if s[i].isdigit() == False:
                break
            digit = int(s[i])
            ans = ans * 10 + digit
            if sign == 1 and ans > INT_MAX:
                return INT_MAX
            if sign == -1 and ans*-1 < INT_MIN:
                return INT_MIN
            i+=1
        
        return int(ans * sign)