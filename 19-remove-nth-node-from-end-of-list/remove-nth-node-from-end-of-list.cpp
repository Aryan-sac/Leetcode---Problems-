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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL && n==1) return NULL;
        int count=0;
        ListNode *temp = head;
        while(temp){
            count++;
            temp = temp->next;
        }
        if (n == count) {
            return head->next;
        }
        int check = count-n;
        temp = head;
        while(temp){
            check--;
            if(check == 0){
                temp->next = temp->next->next;
            }
            temp = temp->next;
        }
        return head;
    }
};