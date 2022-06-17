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
    ListNode* swapPairs(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *cur = head;
        int curNo = 1;
        
        while(cur){
            ListNode *next = cur->next;
            
            if(curNo%2 == 1){
                if(!cur->next)
                    break;
                cur->next = cur->next->next;
                if(cur->next && cur->next->next)
                    cur->next = cur->next->next;
            }else{
                cur->next = prev;
                
                if(curNo == 2)
                    head = cur;
            }
            
            prev = cur;
            cur = next;
            curNo++;
        }
        return head;
    }
};