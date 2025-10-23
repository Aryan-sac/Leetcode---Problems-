class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (head == nullptr) return nullptr;

        unordered_map<Node*, Node*>mp;
        // Creating list without Random Pointers

        Node* temp = head->next, *oldnode, *temp2, *newnode;
        Node* head1 = new Node(head->val);
        head1->next = NULL;
        oldnode = head1;

        mp[head] = head1;

        while(temp != NULL){
            newnode = new Node(temp->val);

            mp[temp] = newnode;

            oldnode->next = newnode;
            oldnode = newnode;
            temp = temp->next;
        }


        // Maintaining Random Connections
        temp = head;
        temp2 = head1;
        while(temp != NULL){
            temp2->random = mp[temp->random];
            temp = temp->next;
            temp2 = temp2->next;
        }
        return head1;
    }
};
