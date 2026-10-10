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

        //Clone and braided right after the original list
        Node* Current = head;
        while (Current){
            Node* Clone = new Node(Current -> val);
            Clone -> next = Current -> next;
            Current -> next = Clone;
            Current = Clone -> next;
        }

        //Assign random
        Current = head;
        while(Current){
            if (Current -> random){
                Current -> next -> random = Current -> random -> next;
            }
            Current = Current -> next -> next;
        }

        //Unbraided
        Current = head;
        Node* DeepCopyHead = head -> next;
        Node* DeepCopyCurrent = DeepCopyHead;
        while (Current){
            Current -> next = Current -> next -> next;
            if (DeepCopyCurrent -> next){
                DeepCopyCurrent -> next = Current -> next -> next;
            }
            Current = Current -> next;
            DeepCopyCurrent = DeepCopyCurrent -> next;
        }
        return DeepCopyHead;
    }
};