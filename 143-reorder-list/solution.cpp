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
    void reorderList(ListNode* head) {
        ListNode* Slow = head;
        ListNode* Fast = head;
        while (Fast -> next && Fast -> next -> next){
            Slow = Slow -> next;
            Fast = Fast ->next -> next;
        }
        ListNode* SecondHalf = Slow -> next;
        Slow -> next = nullptr;

        ListNode* Prev = nullptr;
        ListNode* Curr = SecondHalf;
        while (Curr){
            ListNode* NextNode = Curr -> next;
            Curr -> next = Prev;
            Prev = Curr;
            Curr = NextNode;
        }
        ListNode* FirstHalf = head;
        SecondHalf = Prev;

        while (SecondHalf){
            ListNode* Temp1 = FirstHalf -> next;
            ListNode* Temp2 = SecondHalf -> next;

            FirstHalf -> next = SecondHalf;
            SecondHalf -> next = Temp1;

            FirstHalf = Temp1;
            SecondHalf = Temp2;
        }

    }
};