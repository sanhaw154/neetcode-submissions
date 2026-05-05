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
        bool carry = false;
        ListNode* p = nullptr;
        ListNode* head = p;
        while(l1 != nullptr && l2 != nullptr)
        {
            int sum = l1->val + l2->val + carry;
            if(sum > 9)
            {
                sum -= 10;
                carry = true;
            }
            else
            {
                carry = false;
            }

            if(p == nullptr)
            {
                p = new ListNode(sum);
                head = p;
            }
            else
            {
                p->next = new ListNode(sum);
                p = p->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != nullptr) //l2 == nullptr
        {
            int sum = l1->val + carry;
            if(sum > 9)
            {
                sum -=10;
                carry = true;
            }
            else
            {
                carry = false;
            }

            if(p == nullptr)
            {
                p = new ListNode(sum);
                head = p;
            }
            else
            {
                p->next = new ListNode(sum);
                p = p->next;
            }
            l1 = l1->next;
        }
        while(l2 != nullptr)
        {
            int sum = l2->val + carry;
            if(sum > 9)
            {
                sum -= 10;
                carry = true;
            }
            else
            {
                carry = false;
            }

            if(p == nullptr)
            {
                p = new ListNode(sum);
                head = p;
            }
            else
            {
                p->next = new ListNode(sum);
                p = p->next;
            }
            l2 = l2->next;
        }
        if(carry)
        {
            p->next = new ListNode(carry);
            p = p->next;
        }
        return head;
    }
};
