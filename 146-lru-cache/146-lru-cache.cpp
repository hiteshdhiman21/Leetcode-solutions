class Node{
    public:
    int key;
    int val;    
    Node *next, *prev;  
    
    Node(int key, int val){
        this->key = key;
        this->val = val;
        this->next = this->prev= NULL;
    }
};

class LRUCache {
    
    Node *head, *tail;
    int capacity;
    map<int, Node*> m;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.count(key) == 0) return -1;
        
        Node *resNode = m[key];
        int resVal = resNode->val;
        deleteNode(resNode);
        Node *insNode = new Node(key, resVal);
        insertNode(insNode);
        m[key] = head->next;
        return resVal;
    }
    
    void deleteNode(Node *delNode){
        Node *prevNode = delNode->prev;
        Node *nextNode = delNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        delete(delNode);
    }
    
    void insertNode(Node *insNode){
        Node *headNext = head->next;
        head->next = insNode;
        insNode->prev = head;
        insNode->next = headNext;
        headNext->prev = insNode;
    }
    
    void put(int key, int value) {
         
        if(m.count(key) > 0){
            deleteNode(m[key]);
            m.erase(key);
        }
        
        if(m.size() == capacity){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
       
        Node *insNode = new Node(key, value);
        insertNode(insNode);
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */