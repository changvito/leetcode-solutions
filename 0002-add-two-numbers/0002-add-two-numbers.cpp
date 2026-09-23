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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* P1 = l1;
        ListNode* P2 = l2;
        ListNode* Prev = nullptr;
        int Carry = 0;
        while (P1 != nullptr && P2 != nullptr){
            int Sum = P1 -> val + P2 -> val + Carry;
            P1 -> val = Sum % 10;
            Carry = Sum / 10;
            Prev = P1;
            P1 = P1 -> next;
            P2 = P2 -> next;
        }
        if (P2 != nullptr){
            Prev -> next = P2;
            P1 = P2;
        }
        while (P1 != nullptr && Carry > 0){
            int Sum = P1 -> val + Carry;
            P1 -> val = Sum % 10;
            Carry = Sum / 10;
            Prev = P1;
            P1 = P1 -> next;
        }
        if (Carry > 0){
            Prev -> next = new ListNode(Carry);
        }
        return l1;
    }
};