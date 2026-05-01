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
        int len = 0;
        ListNode* tmp = head;
        while(tmp != nullptr)
        {
            tmp = tmp->next;
            len++;
        }

        n = len - n;
        ListNode* prev = nullptr;
        tmp = head;
        if(len>0 && n>0)
        {
            while(n>0)
            {
                n--;
                prev = tmp;
                tmp = tmp->next;
            }
            prev->next = tmp->next;
        }
        else if(len > 0 && n == 0)
        {
            head = head->next;
        }
        else if(len == 0 && n == 0)
        {
            head = nullptr;
        }
        
        return head;
    }
};
