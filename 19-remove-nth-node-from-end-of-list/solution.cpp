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
        ListNode* Prev = nullptr;
        ListNode* Curr = head;
        while(Curr){
            ListNode* NextNode = Curr -> next;
            Curr -> next = Prev;
            Prev = Curr;
            Curr = NextNode;
        }
        ListNode* Rev = Prev;
        ListNode* Temp = Rev;
        if (n == 1){
            Rev = Rev -> next;
        }
        else {
            for (int i = 1; i < n - 1; i++){
                Temp = Temp -> next;
            }
            Temp -> next = Temp -> next -> next;
        }

        ListNode* Prev1 = nullptr;
        ListNode* Curr1 = Rev;
        while(Curr1){
            ListNode* NextNode = Curr1 -> next;
            Curr1 -> next = Prev1;
            Prev1 = Curr1;
            Curr1 = NextNode;
        }
        return Prev1;       
    }
};