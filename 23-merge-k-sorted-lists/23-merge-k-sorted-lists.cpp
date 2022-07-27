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
    
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        if(l1->val> l2->val)
            swap(l1, l2);
        
        ListNode* head = l1;
        
        
        while(l1 && l2){
            ListNode *tail = NULL;
            while(l1 != NULL && l1->val <= l2->val){
                tail = l1;
                l1 = l1->next;
            }
            tail->next = l2;
            swap(l1, l2);
        }

return head;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        
        int n = lists.size();
        int interval = 1;
        while(interval < n){
            for(int i=0; i<n-interval; i+=2*interval){
                lists[i] = mergeTwoLists(lists[i], lists[i+interval]);
            }
            interval *= 2;
        }
        
        return lists[0];
    }
    //T - O(nlogk) , where n = total nodes
    //S - O(1)
};