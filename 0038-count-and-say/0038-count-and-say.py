class Solution:
    def countAndSay(self, n: int) -> str:
        temp = "1"
        
        for _ in range(1,n):
            i = 0
            new_temp = ""

            while i < len(temp):
                count = 1
                while i+1<len(temp) and temp[i] == temp[i+1]:
                    count += 1
                    i+=1
                new_temp += str(count) + temp[i]
                i+=1

            temp = new_temp
        return temp

# n = 5
# 1
# counter = (1->1)
# temp = 11
# 2
# counter = (1->2)
# temp = 21
# 3
# counter = 2->1, 1->1
# temp = 1211
# counter = 1->3. 2->1
# 3112