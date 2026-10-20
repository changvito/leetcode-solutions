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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* Fast = head;
        ListNode* Slow = head;
        ListNode Dummy;
        Dummy.next = head;
        ListNode* GroupPrev = &Dummy;
        while (Fast != nullptr){
            for (int i = 0; i < k; i++){
                if (Fast == nullptr){
                    return Dummy.next;
                }
                else{
                    Fast = Fast -> next;
                }
            }
            ListNode* Cur = Slow;
            ListNode* Prev = Fast;
            for (int i = 0; i < k; i++){
                ListNode* Temp = Cur -> next;
                Cur -> next = Prev;
                Prev = Cur;
                Cur = Temp;
            }
            GroupPrev -> next = Prev;
            GroupPrev = Slow;
            Slow = Fast;
        }
        return Dummy.next;
    }
};