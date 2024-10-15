class LRUCache {
public:
    class Node{
        public:
            int key;
            int val;
            Node* prev;
            Node* next;

            Node(int _key, int _val){
                key = _key;
                val = _val;
            }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    unordered_map<int, Node*> mapp;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }

    void addNode(Node* new_node){
        Node* temp = head -> next;
        new_node -> next = temp;
        temp -> prev = new_node;

        head -> next = new_node;
        new_node -> prev = head;
    }

    void deleteNode(Node* delNode){
        Node* delprev = delNode -> prev;
        Node* delnext = delNode -> next;

        delprev -> next = delnext;
        delnext -> prev = delprev;
    }
    
    int get(int key) {
        if(mapp.find(key)!=mapp.end()){
            Node* resNode = mapp[key];
            int ans = resNode -> val;
            mapp.erase(key);

            deleteNode(resNode);
            addNode(resNode);
            mapp[key] = head -> next;
            return ans;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if(mapp.find(key)!=mapp.end()){
            Node* existingNode = mapp[key];
            deleteNode(existingNode);
            mapp.erase(key);
        }
        if(mapp.size() == cap){
            mapp.erase(tail -> prev -> key);
            deleteNode(tail -> prev);
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