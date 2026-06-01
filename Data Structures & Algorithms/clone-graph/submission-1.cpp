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
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node*,Node*> map;
        dfs(map,node);
        Node* res = map[node];
        for(auto [oldNode,newNode] : map)
        {
            for(Node* oldAdj : oldNode->neighbors)
            {
                Node* newAdj = map[oldAdj];
                newNode->neighbors.push_back(newAdj);
            }
        }
        return res;
    }
    void dfs(unordered_map<Node*,Node*>& map,Node* node)
    {
        if(!node) return;
        Node* newNode = new Node(node->val);
        map.insert({node,newNode});
        for(Node* adj : node->neighbors)
        {
            if(!map.count(adj)) dfs(map,adj);
        }
    }
};
