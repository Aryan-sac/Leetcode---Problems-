/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
       if(head ==  NULL) return NULL;

        Node *curr = head;
        while(curr != NULL){

            // if child node exist
            if(curr->child != NULL){

                // 1. Flatten the Node
                Node *NEXT  = curr->next;
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = NULL;

                // 2. Finding Tail/(last Node)
                while(curr->next != NULL)
                    curr = curr->next;

                // 3. Attach tail with NEXT ptr
                if(NEXT != NULL)
                {
                    curr->next = NEXT;
                    NEXT->prev = curr;
                }
            }

            curr = curr->next;
        }
        return head; 
    }
};