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
    vector<Node*> noderegister;
    void dfs(Node* actual, Node* clone){
        for(auto i: actual->neighbors){
            if(not noderegister[i->val]){
                Node* newnode=new Node(i->val);
                noderegister[newnode->val]=newnode;
                clone->neighbors.push_back(newnode);
                dfs(i,newnode);


            }
            else{
                clone->neighbors.push_back(noderegister[i->val]);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if(node ==NULL) return NULL;
        noderegister.resize(200,NULL);
        Node* clone=new Node(node->val);
        noderegister[clone->val]=clone;
        dfs(node,clone);
        return clone;
    }
};