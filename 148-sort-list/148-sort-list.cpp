/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    /*ListNode* sortList(ListNode* head) {
        //Insertion sort
        if(head==NULL) return NULL;
        ListNode *smallHead = sortList(head->next);
        
        ListNode *prev = NULL, *temp = smallHead;
        while(temp && temp->val < head->val){
            prev = temp;
            temp = temp->next;
        }
        
        if(!prev){
            head->next = temp;
            return head;
        }else{
            prev->next = head;
            head->next = temp;
            return smallHead;
        }
            
    }
    //T - O(n^2)
    //S - O(1)*/
    
    ListNode *mergeSorted(ListNode *head1, ListNode *head2){
        ListNode *head = new ListNode(0, NULL); 
        ListNode *tail = head;
        
        while(head1 ||  head2){
            if(!head2 || (head1 && head1->val < head2->val)){
                tail->next = head1;
                tail =  tail->next;
                head1 = head1->next;
            }else{
                tail->next = head2;
                tail =  tail->next;
                head2 = head2->next;
            }
        }
                    
        return head->next;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *fast = head, *slow = head;
        
        while(fast && fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode *prevSlow = slow;
        slow = slow->next;
        prevSlow->next = NULL;
        
        head = sortList(head);
        slow = sortList(slow);
        return mergeSorted(head, slow);
    }
    //T - O(n)
    //S - O(1)
};