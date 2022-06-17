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
      /*Reverse cur pair at one time and point the prev Pair's original first(now sec) to cur pair's original sec(now first)*/ 
        ListNode *dummy = new ListNode(-1, head);
        
        ListNode *prev = dummy;//Prev to cur pair 
        ListNode *cur = head;//First in cur pair
        
        while(cur && cur->next){
            //Saving next pair
            ListNode *nxtPair = cur->next->next;
            
            ListNode *sec = cur->next;
            //Reversing
            prev->next = sec; //prev pointer to cur
            cur->next = sec->next;
            sec->next = cur;
            
            
            //Updating for iteration
            prev = cur;
            cur = nxtPair;
        }
        return dummy->next;
    }
    //T - O(n)
    //S - O(1)
};