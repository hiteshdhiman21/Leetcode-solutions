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
    
    ListNode* reverse(ListNode *head){
        ListNode *to = NULL;
        ListNode *from = head;
        
        while(from){
            ListNode *next = from->next;
            from->next = to;
            to = from;
            from = next;
        }
        
        return to;
    }
    
    void reorderList(ListNode* head) {
        
        if(head == NULL || head->next == NULL)
            return;
        
      /*Step-1. Find the middle point(start of second hald).
        Step-2. Reverse the second half.
        Step-3. Merge the first and the second half iteratively.*/
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow;
        slow = slow->next;
        fast->next = NULL;
        slow = reverse(slow);
        
        fast = head;
        ListNode *tail = new ListNode(0, NULL);
        head = tail;
        
        
        while(fast || slow){
            if(fast){
                tail->next = fast;
                tail = fast;
                fast = fast->next;
            }
            
            if(slow){
                tail->next = slow;
                tail = slow;
                slow = slow->next;
                
            }
        }
        
        head = head->next;
    }
    //T - O(n^2)
    //S - O(1)
};