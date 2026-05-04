/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        unordered_map<Node*,Node*> map;
        
        
        Node* old = head;
        Node* newHead = new Node(old->val);
        Node* prev = newHead;
        map[old] = prev;
        old = old->next;
        while(old != NULL)
        {
            Node* newNode = new Node(old->val);
            map[old] = newNode;
            prev->next = newNode;
            prev = newNode;
            old = old->next;
        }
        prev->next = NULL;
        
        Node* p = head;
        while(p != NULL)
        {
            map[p]->random = map[p->random];
            p = p->next;
        }
        return newHead;
    }
};
