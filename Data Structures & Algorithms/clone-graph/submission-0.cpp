/*
// Definition for a Node.
class Node { 
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*,Node*> map;
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        
        queue<Node*> q;
        q.push(node);
        while(!q.empty()) //bfs traversal
        {
            Node* cur = q.front();
            q.pop();
            Node* newNode = new Node(cur->val);
            for(Node* adj : cur->neighbors)
            {
                if(!map.count(adj)) q.push(adj);
                
            }
            map.insert({cur,newNode});
        }
        Node* newRoot = map[node];
        for(auto [cur,newNode] : map)
        {
            for(Node* curAdj : cur->neighbors )
            {
                newNode->neighbors.push_back(map[curAdj]);
            }
        }

        return newRoot;
    }
};
