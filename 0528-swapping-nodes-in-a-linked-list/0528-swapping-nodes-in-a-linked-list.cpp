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
    ListNode* swapNodes(ListNode* head, int k) {
        // using the technique of slow and fast pointers
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        ListNode* temp = head;
        int n = 0;
        while(temp){
            n++;
            temp = temp->next;
        }

        for(int i = 1; i < k; i++){
            temp1 = temp1->next;
        }

        for(int j = 1; j < n-k+1; j++){
            temp2 = temp2->next;
        }

        n = temp1->val;
        temp1->val = temp2->val;
        temp2->val = n;

        return head;
    }
};