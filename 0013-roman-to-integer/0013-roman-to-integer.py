class Solution:
    def romanToInt(self, s: str) -> int:
        roman_map = {
            "I" : 1,
            "V" : 5,
            "X" : 10,
            "L" : 50,
            "C" : 100,
            "D" : 500,
            "M" : 1000
        }

        n = len(s)
        sum = 0

        for i in range(n):
            if i + 1 < n and roman_map[s[i]] < roman_map[s[i+1]]:
                sum -= roman_map[s[i]]
            else:
                sum += roman_map[s[i]]
        
        return sum