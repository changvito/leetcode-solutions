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
        ListNode* Dummy = new ListNode(0);
        ListNode* Curr = Dummy;
        int Carry = 0;
        while (l1 != nullptr || l2 != nullptr || Carry != 0){
            int Sum = Carry;
            if (l1 != nullptr){
                Sum += l1 -> val;
                l1 = l1 -> next;
            }
            if (l2 != nullptr){
                Sum += l2 -> val;
                l2 = l2 -> next;
            }
            Carry = Sum / 10;
            Curr -> next = new ListNode(Sum % 10);
            Curr = Curr -> next;
        }
        ListNode* Ans = Dummy -> next;
        delete Dummy;
        return Ans;
    }
};