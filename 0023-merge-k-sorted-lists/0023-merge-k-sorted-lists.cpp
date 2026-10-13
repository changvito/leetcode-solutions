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
        if (lists.empty()){
            return nullptr;
        }
        return MergeRange(lists, 0, lists.size() - 1);
    }
private:
    ListNode* MergeRange(vector<ListNode*>& lists, int Left, int Right){
        if (Left == Right){
            return lists[Left];
        }
        int Mid = Left + (Right - Left) / 2;
        ListNode* LeftList = MergeRange(lists, Left, Mid);
        ListNode* RightList = MergeRange(lists, Mid + 1, Right);
        return MergeTwo(LeftList, RightList);
    }
    ListNode* MergeTwo(ListNode* A, ListNode* B){
        ListNode Dummy;
        ListNode* Tail = &Dummy;
        while (A != nullptr && B != nullptr){
            if (A -> val <= B -> val){
                Tail -> next = A;
                A = A-> next;
            }
            else{
                Tail -> next = B;
                B = B -> next;
            }
            Tail = Tail -> next;
        }
        Tail -> next = (A != nullptr) ? A : B;
        return Dummy.next;
    }
};