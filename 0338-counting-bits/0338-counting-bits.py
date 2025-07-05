class Solution:
    def countBits(self, n: int) -> List[int]:
        ans = []

        for i in range(n+1):
            element = i
            count = 0

            while element > 0:
                if element % 2 == 1:
                    count += 1

                element //= 2

            ans.append(count)

        return ans    
            