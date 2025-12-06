class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) % groupSize != 0:
            return False

        count = Counter(hand)
        minheap = list(count.keys())
        heapq.heapify(minheap)

        while minheap:
            first = minheap[0]

            for card in range(first, first + groupSize):
                if card not in minheap:
                    return False

                count[card] -= 1

                if count[card] == 0:
                    heapq.heappop(minheap)
                    del count[card]

        return True