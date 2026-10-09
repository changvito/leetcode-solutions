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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode Dummy(0, head);
        ListNode* Fast = &Dummy;
        ListNode* Slow = &Dummy;
        for (int i = 0; i < n ; i++){
            Fast = Fast -> next;
        }
        while (Fast -> next != nullptr){
            Fast = Fast -> next;
            Slow = Slow -> next;
        }
        Slow -> next = Slow -> next -> next;
        return Dummy.next;
    }
};