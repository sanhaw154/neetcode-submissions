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
        if ( head->next == nullptr) return;
        ListNode* end = head;
        while(end->next->next != nullptr)
        {
            end = end->next;
        }
        if(head == end) return;
        end->next->next = head->next;
        head->next = end->next;
        head = end->next->next;
        end->next = nullptr;
        return reorderList(head);
    }
};
