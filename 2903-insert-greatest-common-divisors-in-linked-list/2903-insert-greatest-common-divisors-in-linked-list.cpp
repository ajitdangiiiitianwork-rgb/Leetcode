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
    int gcd(int a, int b){
        while(b != 0){
            int t = b;
            b = a%b;
            a = t;
        }

        return a;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;
        while(curr && curr->next){
            ListNode* Next = curr->next;
            int value = gcd(curr->val, curr->next->val);
            ListNode* newNode = new ListNode(value);

            newNode->next = curr->next;
            curr->next = newNode;

            curr = Next;
        }

        return head;
    }
};