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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
    ListNode *curListNode;
public:
    
    TreeNode* sortedListToBST(ListNode* head) {
        
        int len = 0;
        curListNode = head;
        while(curListNode != NULL){
            len++;
            curListNode = curListNode->next;
        }
        
        curListNode = head;
        return build(0, len-1);
    }
    
    TreeNode* build(int start, int end){
        if(start > end) return NULL;
        
        int mid = start+(end-start)/2;
        
        TreeNode *leftHead = build(start, mid-1);
        TreeNode *head = new TreeNode(curListNode->val);
        head->left = leftHead;
        
        curListNode = curListNode->next;
        TreeNode *rightHead = build(mid+1, end);
        head->right = rightHead;      
        
        return head;
    }
    //T - O(n)
    //S - O(1)
};