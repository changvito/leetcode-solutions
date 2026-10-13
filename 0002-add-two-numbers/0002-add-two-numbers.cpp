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
        ListNode* Current1 = l1;
        ListNode* Current2 = l2;
        ListNode* Prev = nullptr;
        int Carry = 0;
        
        //Add two list
        while (Current1 != nullptr && Current2 != nullptr){
            int Sum = Current1 -> val + Current2 -> val + Carry;
            Current1 -> val = Sum % 10;
            Carry = Sum / 10;
            Prev = Current1;
            Current1 = Current1 -> next;
            Current2 = Current2 -> next;
        }

        //if list1 end first
        if (Current1 == nullptr){
            Prev -> next = Current2;
            Current1 = Current2;
        }

        //Propogate carry through remaining list
        while(Current1 != nullptr){
            int Sum = Current1 -> val + Carry;
            Current1 -> val = Sum % 10;
            Carry = Sum / 10;
            Prev = Current1;
            Current1 = Current1 -> next;
        }

        //List end, but carry
        if (Carry > 0){
            Prev -> next = new ListNode(Carry);
        }

        return l1;
    }
};