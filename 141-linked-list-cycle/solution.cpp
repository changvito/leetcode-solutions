/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set <ListNode*> Visited;
        while (head != nullptr){
            if (Visited.count(head)){
                return true;
            }
            Visited.insert(head);
            head = head -> next;
        }
        return false;
    }
};