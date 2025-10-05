class LRUCache {
public:
    class Node{
        public:
            int key;
            int val;
            Node* next;
            Node* prev;

            Node(int _key, int _val){
                key = _key;
                val = _val;
            }
    };

    Node*head = new Node(-1, -1);
    Node*tail = new Node(-1, -1);
    unordered_map<int, Node*> mapp;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }

    void delNode(Node* resNode){
        Node* prevNode = resNode -> prev;
        Node* nextNode = resNode -> next;

        prevNode -> next = nextNode;
        nextNode -> prev = prevNode;
    }

    void addNode(Node* resNode){
        resNode -> next = head -> next;
        resNode -> prev = head;
        head -> next -> prev = resNode;
        head -> next = resNode;
    }
    
    int get(int key) {
        if (mapp.find(key) != mapp.end()){
            Node* resNode = mapp[key];
            int ans = resNode -> val;
            mapp.erase(key);

            // delete Node 
            delNode(resNode);
            // Insert Node 
            addNode(resNode);
            mapp[key] = head -> next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mapp.find(key) != mapp.end()){
            Node* resNode = mapp[key];
            delNode(resNode);
            mapp.erase(key);
        }
        if(mapp.size()== cap){
            mapp.erase(tail -> prev -> key);
            delNode(tail -> prev);
        }
        addNode(new Node(key, value));
        mapp[key] = head -> next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */