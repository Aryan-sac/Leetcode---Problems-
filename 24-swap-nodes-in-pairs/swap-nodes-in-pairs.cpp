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
        ListNode *c=head;
        int t;
        while(c != NULL && c->next != NULL){
            t = c->val;
            c->val = c->next->val;
            c->next->val = t;
            c = c->next->next;
        }
        return head;
    }
};