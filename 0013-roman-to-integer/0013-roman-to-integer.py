class Solution:
    def romanToInt(self, s: str) -> int:
        mapp = {
            "I" : 1,
            "V" : 5,
            "X" : 10,
            "L" : 50,
            "C" : 100,
            "D" : 500,
            "M" : 1000
        }

        summ = 0
        n = len(s)
        for i in range(n):
            if i+1 < n and mapp[s[i]] < mapp[s[i+1]]:
                summ -= mapp[s[i]]
            else:
                summ += mapp[s[i]]
        
        return summ