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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> MinHeap;
        for (ListNode* Head : lists){
            if (Head != nullptr){
                MinHeap.push(Head);
            }
        }
        ListNode Dummy;
        ListNode* Tail = &Dummy;
        while( !MinHeap.empty()){
            ListNode* Temp = MinHeap.top();
            MinHeap.pop();
            Tail -> next = Temp;
            Tail = Temp;
            if (Temp -> next != nullptr){
                MinHeap.push(Temp -> next);
            }
        }
        return Dummy.next;
    }
private:
    struct Compare{
        bool operator()(ListNode* A, ListNode* B){
            return A -> val > B -> val;
        }
    };
};