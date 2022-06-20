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
    
    ListNode *reorder(ListNode *head){
        if(head == NULL || head->next == NULL || head->next->next == NULL)
            return head;
        
        ListNode* tail = head->next;
        while(tail->next && tail->next->next)
            tail = tail->next;
        
        ListNode *prevTail = tail;
        tail = tail->next;
        prevTail->next = NULL;
        
        tail->next = reorder(head->next);
        head->next = tail;
        return head;
    }
    
    void reorderList(ListNode* head) {
        reorder(head);    
    }
    //T - O(n^2)
    //S - O(1)
};