/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head){
            return nullptr;
        }
        unordered_map<Node*, Node*> mp;
        Node* Cur = head;
        while (Cur){
            mp[Cur] = new Node(Cur -> val);
            Cur = Cur -> next;
        }

        Cur = head;
        while (Cur){
            mp[Cur] -> next = mp[Cur -> next];
            mp[Cur] -> random = mp[Cur -> random];
            Cur = Cur ->  next; 
        }
        return mp[head];
    }
};