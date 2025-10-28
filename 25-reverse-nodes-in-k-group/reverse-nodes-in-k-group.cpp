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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp = head, *start, *NEXT,*curr, *lastNode, *newhead=NULL,*prevTail;
        int count = 0;
        // count nodes
        while(temp != NULL){
            count++;
            temp = temp->next;
        }

        if(count < k) return head;
        temp = head;
        while(count >= k){
            
            int c = 0;
            start = temp;
            while(c < k){
                if (c == 0) lastNode = start; // this will be tail after reverse
                temp = temp->next;
                c++;
            }
            c = 0;
            curr = temp;
            while(c < k){
                NEXT = start->next;
                start -> next = curr;
                curr = start;
                start = NEXT;
                c++;
            }
            if(newhead == NULL){
                newhead = curr;
            }
            else
                prevTail->next = curr;  // connect with previous tail

            // Update previous tail to current group's tail
            prevTail = lastNode;

            count = count - k;
        }
        return newhead;
    }
};