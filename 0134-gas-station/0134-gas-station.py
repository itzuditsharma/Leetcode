class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        balance = 0
        loss = 0
        st_index = 0

        for i in range(len(gas)):
            balance += gas[i] - cost[i]
            if balance < 0:
                st_index = i + 1
                loss += balance
                balance = 0

        if balance + loss >= 0:
            return st_index
        else:
            return -1
