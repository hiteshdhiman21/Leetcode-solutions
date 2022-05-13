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
    
    int length(ListNode* head){
        int len = 0;
        while(head){
            head = head->next;
            len++;
        }
        return len;
    }
    
    
    ListNode* rotateRight(ListNode* head, int k) {
        int len = length(head);
        if(len == 0) return head;
        k = k%len;
        if(k==0) return head;
        
        ListNode* fast = head;
        ListNode *slow = head;
        
        for(int i=1; i<=k; i++){
            fast = fast->next;
        }
        
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode* nh = slow->next;
        slow->next = NULL;
        fast->next = head;
        return nh;
    }
};