class LRUCache:
    class Node:
        def __init__(self, key, value):
            self.key = key
            self.value = value
            self.prev = None
            self.next = None
    
    def __init__(self, capacity: int):
        self.cap = capacity
        self.mapp = {}
        self.head = self.Node(-1, -1)
        self.tail = self.Node(-1, -1)
        self.head.next = self.tail
        self.tail.prev = self.head

    def delNode(self,resNode):
        prevNode = resNode.prev
        nextNode = resNode.next
        prevNode.next = nextNode
        nextNode.prev = prevNode
    
    def addNode(self,resNode):
        currNode = self.head.next
        resNode.next = currNode
        resNode.prev = self.head
        currNode.prev = resNode
        self.head.next = resNode

    def get(self, key: int) -> int:
        if key in self.mapp.keys():
            resNode = self.mapp[key]
            ans = resNode.value
            self.delNode(resNode)
            self.addNode(resNode)
            self.mapp[key] = self.head.next
            return ans
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.mapp.keys():
            resNode = self.mapp[key]
            del self.mapp[key]
            self.delNode(resNode)
        if len(self.mapp) == self.cap:
            del self.mapp[self.tail.prev.key]
            self.delNode(self.tail.prev)
        newNode = self.Node(key, value)
        self.addNode(newNode)
        self.mapp[key] = self.head.next



# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)