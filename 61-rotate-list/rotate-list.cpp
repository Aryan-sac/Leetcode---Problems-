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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || head == NULL || head->next == NULL) return head;
        ListNode *temp=head, *p;
        int nodes=0;
        temp = head;
        while(temp != NULL)
        {
            nodes++;
            temp = temp->next;
        }
        k = k%nodes;
        if (k == 0) return head;
        k = nodes-k;
        temp = head;
        for(int i=1; i<k; i++){
            temp = temp->next;
        }
        p=temp->next;
        temp->next=NULL;
        temp = p;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = head;
        return p;
    }
};