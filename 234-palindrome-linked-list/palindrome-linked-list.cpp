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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        
        ListNode *slow=head, *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Step 2: Reverse second half
        ListNode* prev = NULL;
        ListNode* curr = slow;
        while (curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Step 3: Compare first half and reversed second half
        ListNode* left = head;
        ListNode* right = prev; // head of reversed second half
        while (right != NULL) {
            if (left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }

        return true;
    }
};