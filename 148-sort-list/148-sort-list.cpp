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
        ListNode *head = new ListNode(0, NULL);  //Dummy Node
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
            //Slow will reach to middle element in case of Odd no. of elements and First middle element in case of Even no. of elements
            fast = fast->next->next;
            slow = slow->next;
        }
        
        //Cutting linked list into two halves
        ListNode *prevSlow = slow;
        slow = slow->next;
        prevSlow->next = NULL; 
        
        //Passing smaller linked lists and believe in recursion to return both in a sorted manner
        head = sortList(head);
        slow = sortList(slow);
        
        //Finally merge both and return a full sorted linked list
        return mergeSorted(head, slow);
    }
    //T - O(nlogn)
    //S - O(1)
};