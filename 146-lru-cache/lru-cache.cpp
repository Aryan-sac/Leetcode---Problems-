class LRUCache {
public:

    class node{
        public:
            int key, val;
            node* next;
            node* prev;

            node(int k, int v){
                key = k;
                val = v;
                next = prev = NULL;
            }
    };

    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);

    unordered_map<int, node*> mp;

    int limit;
    LRUCache(int capacity) {
        limit = capacity;
        head -> next = tail;
        tail -> prev = head;
    }

    void addNode(node *newNode){
        newNode->next = head->next;
        newNode->prev = head;

        head->next->prev = newNode;
        head->next = newNode;
    }
    void delNode(node* delnode){
        delnode->prev->next = delnode->next;
        delnode->next->prev = delnode->prev;
    
        delete delnode;
    }

    int get(int key) {
        // if key not present then return -1
        if(mp.find(key) == mp.end()) return -1;

        int ans = mp[key]->val;
        // delete LRU key and (old Address) pair and put same at MRU position

        delNode(mp[key]);           // Delete that node
        mp.erase(key);              // also erase that key with OLD ADDRESS pair

        // REINSERTING in MRU position
        node* ReInsert = new node(key, ans);
        addNode(ReInsert);          // Re-insert that node
        mp[key] = ReInsert;         // Maintaing key and NEW ADDRESS pair in map

        return ans; 
    }
    
    void put(int key, int value) {
        // case 1.  IF SAME KEY WITH DIFFERENT VALUE PRESENT
        if(mp.find(key) != mp.end()){
            delNode(mp[key]);
            mp.erase(key); // also remove old address
        }

        // case 2.  IF LIMIT FULL
        if(mp.size() == limit){
            mp.erase(tail->prev->key);  // remove LRU pair from map
            delNode(tail->prev);        // also delete that node
        }

        // INSERTING NEW NODE
        node *newNode = new node(key, value);
        addNode(newNode);               // add new node at starting position MRU
        mp[key] = newNode;              // also store new node address with corresponding key
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */