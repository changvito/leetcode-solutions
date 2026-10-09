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

        //Use Tortoise & Hare Algo to cut the given list in half
        ListNode* Slow = head;
        ListNode* Fast = head;
        while (Fast -> next && Fast -> next -> next){
            Slow = Slow -> next;
            Fast = Fast -> next -> next;
        }
        ListNode* SecondHalf = Slow -> next;
        Slow -> next = nullptr;

        //Reverse the SecondHalf List
        ListNode* Curr = SecondHalf;
        ListNode* Prev = nullptr;
        while(Curr){
            ListNode* Next = Curr -> next;
            Curr -> next = Prev;
            Prev = Curr;
            Curr = Next;
        }
        ListNode* FirstHalf = head;
        SecondHalf = Prev;

        //Braided
        while (SecondHalf){
            ListNode* Temp1 = FirstHalf -> next;
            ListNode* Temp2 = SecondHalf -> next;
            SecondHalf -> next = Temp1;
            FirstHalf -> next = SecondHalf;
            FirstHalf = Temp1;
            SecondHalf = Temp2;
        }
    }
};