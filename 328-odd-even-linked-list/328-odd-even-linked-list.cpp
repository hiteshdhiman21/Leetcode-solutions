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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd = head;
        ListNode* evenHead = (head && head->next)?head->next:NULL;
        ListNode *even = evenHead;
        
        while(odd && even){
            if(odd->next){ //To ensure odd remains at last oddNode
                odd->next = odd->next->next;
                if(odd->next)
                    odd = odd->next;
            }
            
            if(even->next){ //To ensure stopping condition of while loop
                even->next = even->next->next;
            }
            
            if(even->next)
                    even = even->next;
                else
                    break;
        }
        
        if(odd)
        odd->next = evenHead;
        
        return head;
    }
    //T - O(n)
    //S - O(1)
};