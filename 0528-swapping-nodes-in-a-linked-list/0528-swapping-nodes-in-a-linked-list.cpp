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
        
        ListNode* temp1 = head;
        ListNode* temp2 = head;

        for(int i = 1; i < k; i++) temp1 = temp1->next;
        ListNode* dummy = temp1;
        while(dummy->next){
            temp2 = temp2->next;
            dummy = dummy->next;
        }

        swap(temp1->val, temp2->val);
        return head;

        return head;
    }
};