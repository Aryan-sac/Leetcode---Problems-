/* Linked List Node Structure
class Node {
  public:
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = nullptr;
    }
};
*/
class compare{
    public:
        bool operator()(Node* a, Node*b){
            return a->data > b->data;
        }
};
class Solution {
  public:
    
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
        priority_queue<Node*, vector<Node*>, compare>pq(arr.begin(), arr.end());
        Node* head = NULL, *temp = NULL;
        while(!pq.empty()){
            if(head == NULL){
                head = pq.top();
                temp = head;
                pq.pop();
                if(head -> next != NULL)
                    pq.push(head->next);
            }
            else{
                temp -> next = pq.top();
                pq.pop();
                if(temp->next->next != NULL)
                    pq.push(temp->next->next);
                
                temp = temp->next;
            }
        }
        return head;
        
    }
};