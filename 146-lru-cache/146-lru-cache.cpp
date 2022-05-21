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
    
    //Used Doubly-linked list and hashmap
    //Using hashmap we can find address for any node in O(1)
    //For linked-list, using that address we can delete any node in O(1)
    //For linked-list we can add any node in O(1) and store that address in map and deleting the old node if present and remove old address.
    //Linkedlist: head->n1->n2->n3->n4->tail
    //n1, n2, n3, n4 are stored in order of increasing last used time. n1 is recent. n4 is used long back.
    //If capacity is full, we will first delete the tail->prev node for making new place. and we will insert any recently accessed node after head. 
    //Used dummy nodes head and tail so that in case of 0 nodes we don't have to deal separately with the NULL pointers
    //map -> (key, node address) pairs
    //node-> val, *next, *prev;
    Node *head, *tail;
    int capacity;
    unordered_map<int, Node*> m;
    
public:
    LRUCache(int& capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        
        //Step-1. if key not present, return -1. Else
        //Step-2. Take key node's address from the map and access the node.
        //Step-3. Store its val in resVal.
        //Step-4. delete that old node and its address.
        //Step-5. Make new node for same key and insert after the head. Also add new address in map. 
        //Step-6. Return resval
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
         //Step-1. if key already present, delete old node from the linked-list and also remove it from map.
        //Step-2. Now if size is already full, delete tail->prev node and remove its address from the map.
        //Step-3. Insert the new node after head and insert new address in map.
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
    //T - O(n)   // O(1) for all the operations
    //S - O(1)
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */