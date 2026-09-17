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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for(int i=0; i<lists.size(); i++){
            if(lists[i] != NULL)
            pq.push({lists[i]->val, lists[i]});
        }
        ListNode *head=NULL, *temp=NULL, *pre=NULL;
        while(!pq.empty()){
            if(head == NULL)
            {
                pre = pq.top().second;
                head = pre;
                pq.pop();
                if(pre->next != NULL)
                {
                    pq.push({pre->next->val, pre->next});
                }
                temp = head;
            }
            else{
                pre = pq.top().second;
                temp->next = pre;
                pq.pop();
                if(pre->next != NULL)
                {
                    pq.push({pre->next->val, pre->next});
                }
                temp = temp->next;
            }
        }
        return head;
    }
};