class Node{
    public:
    int key;
    int val;
    int freq;
    Node *prev;
    Node *next;
    
    
    Node(int key, int val, int freq){
        this->key = key;
        this->val = val;
        this->freq = freq;
        this->prev = this->next = NULL;
    }
};

class LFUCache {
public:
    int capacity;
    Node* head, *tail;
    map<int, Node*> freqTail; //To find tail for a group of each frequency nodes.
    map<int, Node*> m; //To find address for each key-node.
    
public:
    
    LFUCache(int& capacity) {
        this->head = new Node(-1, -1, INT_MAX);
        this->tail = new Node(-1, -1, INT_MIN);
        this->head->next = this->tail;
        this->tail->prev= this->head;
        this->capacity = capacity;
        freqTail[INT_MAX] = head;
        freqTail[INT_MIN] = tail;
    }
    
    void deleteNode(Node *delNode){
        Node *prevNode = delNode->prev;
        Node *nextNode = delNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        if(freqTail[delNode->freq] == delNode){
            freqTail.erase(delNode->freq);
            freqTail[prevNode->freq] = prevNode;
        }
        
    }
    
    void insertNode(Node *insNode){
        if(freqTail.count(insNode->freq) == 0) freqTail[insNode->freq] = insNode;
        
        Node *prevNode = (*(freqTail.upper_bound(insNode->freq))).second;
        Node *nextNode = prevNode->next;
        prevNode->next = insNode;
        nextNode->prev = insNode;
        insNode->prev = prevNode;
        insNode->next = nextNode;
      
    }
    
    int get(int key) {
        
        if(capacity == 0 || m.count(key) == 0) return -1;
        
        Node *resNode = m[key];
        int resVal = resNode->val;
        int resFreq = resNode->freq;
        resFreq++;
        deleteNode(resNode); //
        m.erase(key);
        
        Node *newNode = new Node(key, resVal, resFreq);
        m[key] = newNode;
        insertNode(newNode);
        return resVal;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;
        int freq = 0;
               
        if(m.count(key)> 0){
            Node* resNode = m[key];
            freq = resNode->freq;
            deleteNode(resNode);
            m.erase(key);
        }
        
        
        if(m.size() == capacity){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        freq++;
        
        
        
        Node *newNode = new Node(key, value, freq);
        m[key] = newNode;
        insertNode(newNode);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */