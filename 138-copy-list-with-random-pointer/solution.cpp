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
        if(!head){
            return nullptr;
        }
        Node* Cur = head;
        while (Cur){
            Node* Clone = new Node(Cur -> val);
            Clone -> next = Cur -> next;
            Cur -> next = Clone;
            Cur = Clone -> next;
        }
        Cur = head;
        while (Cur){
            if (Cur -> random){
                Cur -> next -> random = Cur -> random -> next;
            }
            Cur = Cur -> next -> next;
        }
        Cur = head;
        Node* newHead = head -> next;
        Node* cloneCur = newHead;
        while (Cur){
            Cur -> next = Cur -> next -> next;
            if (cloneCur -> next){
                cloneCur -> next = cloneCur -> next -> next;
            }
            Cur = Cur -> next;
            cloneCur = cloneCur -> next;
        }
        return newHead;
    }
};