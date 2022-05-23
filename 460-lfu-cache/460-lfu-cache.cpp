class Node{
    public:
    int key;
    int val;  
    int freq;
    Node *next, *prev;  
    
    Node(int key, int val, int freq){
        this->key = key;
        this->val = val;
        this->freq = freq;
        this->next = this->prev= NULL;
    }
};

class LRU {
    public:
    Node *head, *tail;
    int size;
    
    public:
    LRU(){
        this->head = new Node(-1, -1, -1);
        this->tail = new Node(-1, -1, -1);
        head->next = tail;
        tail->prev= head;
        this->size= 0;
    }
       
    void deleteNode(Node *delNode){
        Node *prevNode = delNode->prev;
        Node* nextNode = delNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        size--;
    }
    
    void insertNode(Node *insNode){
        
        Node *nextNode = head->next;
        head->next = insNode;
        insNode->prev = head;
        insNode->next = nextNode;
        nextNode->prev = insNode;
        size++;
    }
    
};

//Simply used lists of LRU cache with some modifications.
//We maintain a list for each possible frequency using map freqList which stores (freq, list)
class LFUCache {
public:
    int mn_freq;
    int capacity;
    unordered_map<int, LRU*> freqList;
    unordered_map<int, Node*> m;
    
public:
    
    LFUCache(int& capacity) {
        this->capacity = capacity;
        this->mn_freq = 0;
    }
    
    int get(int key) {
        //Basically we get the value at key and transfer the node from list of old freq to new freq. 
        //Step-1. Get the resNode address using m[key].
        //Step-2. Call deleteNode on freqList[resFreq], it will go to LRU of resFreq nodes and remove node from there. Now if old_freq = mn_freq and freqList[old_freq] contians no elements, set mn_freq = old_freq+1/
        //Step-3. Make a new node with freq = oldFreq+1. and insert it in freqList[resFreq+1].
         
        if(!m.count(key)) return -1;
        
        Node *resNode = m[key];
        int resVal = resNode->val;
        int resFreq = resNode->freq;
        freqList[resFreq]->deleteNode(resNode);
        m.erase(key);
        
        if(mn_freq == resFreq && freqList[resFreq]->size == 0) mn_freq = resFreq+1;
        
        resFreq++;
        Node *newNode = new Node(key, resVal, resFreq);
        m[key] = newNode;
        if(freqList.count(resFreq) == 0){
            freqList[resFreq] = new LRU;
        }
        
        freqList[resFreq]->insertNode(newNode); 
      
        return resVal;
    }
    
    void put(int key, int value) {
        //Step-1. First remove the old node for this key.
        //Step-2. If size == capacity, call deleteNode on freqList[mn_freq], it will go to LRU of mn_freq nodes and remove LRU node from there. Now if old_freq = mn_freq and freqList[old_freq] contians no elements, set mn_freq = old_freq+1
        //Step-3. Make a new node with freq = oldFreq+1. and insert it in freqList[freq].
        //Step-4. If oldFreq == 0, update mn_freq = 1. 
        
        if(capacity == 0) return;
        
        int oldFreq = 0;
       
        if(m.count(key)>0){
            Node*oldNode = m[key];
            oldFreq = oldNode->freq;
            m.erase(key);
            freqList[oldFreq]->deleteNode(oldNode);
            
            if(mn_freq == oldFreq && freqList[oldFreq]->size== 0) mn_freq = oldFreq+1;
        }
        
        oldFreq++;
        
        
        if(m.size() == capacity){
            
            Node *toDel = freqList[mn_freq]->tail->prev;
            int toDelKey = toDel->key;
            freqList[mn_freq]->deleteNode(toDel);
            m.erase(toDelKey);
        }
        
        Node *newNode = new Node(key, value, oldFreq);
        if(freqList.count(oldFreq) == 0) freqList[oldFreq] = new LRU;
        freqList[oldFreq]->insertNode(newNode);
        m[key] = newNode;
        if(oldFreq == 1) mn_freq = 1;  
    }
    
    //T - O(1) for all operations
    //S - O(n)
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */