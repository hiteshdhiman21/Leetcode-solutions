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
    
    priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq; 
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = NULL, *tail = NULL;
        
        for(int i=0; i<lists.size(); i++){
            if(lists[i] != NULL)
                pq.push({lists[i]->val,lists[i]});
        }
            
        
        while(!pq.empty()){
            auto[val, node] = pq.top(); pq.pop();
            if(head == NULL) head = tail = node;
            else{
                tail->next = node;
                tail = node;
            }
            
            if(node->next)
                pq.push({node->next->val, node->next});
        }
        
        return head;
    }
    //T - O(nlogk) , where n = total nodes
    //S - O(k)
};