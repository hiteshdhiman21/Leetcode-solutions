/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* head2 = NULL;
        
        Node* temp1 = head;
        Node *temp2 = NULL;
        while(temp1){
            Node *newNode = new Node(temp1->val, temp1->next, temp1->random);
            temp2 = newNode;
            if(head2 == NULL) head2 = temp2;
            temp1->next = temp2;
            temp1 = temp1->next->next;
        }
        
        //cout << "Here";
        
        temp2 = head2;
        while(temp2){
            if(temp2->random)
            temp2->random = temp2->random->next;
            if(temp2->next)
            temp2 = temp2->next->next;
            else
                temp2 = NULL;
        }
        
      //  cout << "Here";
        temp1 = head;
        temp2 = head2;
        
        while(temp1 && temp2){
            temp1->next = temp2->next;
            if(temp1->next)
            temp2->next = temp1->next->next;
            temp1 = temp1->next;
            temp2= temp2->next;
        }
        
        return head2;
    }
};