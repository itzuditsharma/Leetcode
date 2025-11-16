class LRUCache:
    class Node:
        def __init__(self, key, value):
            self.key = key
            self.value = value
            self.prev = None
            self.next = None

    def __init__(self, capacity: int):
        self.cap = capacity
        self.map = {}    #key -> Node
        self.head = self.Node(-1, -1)
        self.tail = self.Node(-1, -1)
        self.head.next = self.tail
        self.tail.prev = self.head

    # {1:2, 2:3}

    def addNode(self, node):
        currNode = self.head.next
        node.next = currNode
        node.prev = self.head
        currNode.prev = node
        self.head.next = node

    def delNode(self, node):
        prevNode = node.prev
        nextNode = node.next
        prevNode.next = nextNode
        nextNode.prev = prevNode

    def get(self, key: int) -> int:
        if key in self.map.keys():
            node = self.map[key]
            ans = node.value
            self.delNode(node)
            self.addNode(node)
            self.map[key] = self.head.next
            return ans

        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.map.keys():
            node = self.map[key]
            self.delNode(node)
            del self.map[key]
        
        if len(self.map) == self.cap:
            del self.map[self.tail.prev.key]
            self.delNode(self.tail.prev)

        newNode = self.Node(key, value)
        self.addNode(newNode)
        self.map[key] = self.head.next


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)