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
    ListNode* reverseList(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nextNode = curr->next;
        while(nextNode){
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            nextNode = curr->next;
        }
        curr->next = prev;
        prev = curr;
        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        if(head == NULL) return head;
        head = reverseList(head);

        ListNode* curr = head;
        int maxVal = curr->val;

        while(curr && curr->next){
            if(curr->next->val < maxVal){
                curr->next = curr->next->next;
            }
            else{
                curr = curr->next;
                maxVal = curr->val;
            }
        }

        head = reverseList(head);
        return head;
    }
};