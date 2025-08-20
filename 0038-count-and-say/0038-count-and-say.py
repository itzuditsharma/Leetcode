class Solution:
    def countAndSay(self, n: int) -> str:
        temp = "1"
        for _ in range(1, n):
            new_temp  = ""
            i=0
            while i < len(temp):
                count = 1
                while i + 1 < len(temp) and temp[i] == temp[i+1]:
                    i += 1
                    count += 1
                new_temp += str(count) + temp[i]
                i+=1
            temp = new_temp
        return temp
