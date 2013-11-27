/*
 Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

OJ's undirected graph serialization:

Nodes are labeled uniquely.
We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.

As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

    First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
    Second node is labeled as 1. Connect node 1 to node 2.
    Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.

Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/

*/
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    typedef UndirectedGraphNode Node;
    typedef unordered_map<Node*,Node*> MAP;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        return cloneGraph_1(node);
        return cloneGraph_2(node);
    }
    // DFS
    Node *cloneGraph_1(Node *node) {
        MAP map;
        return cloneGraphRe(node, map);
    }
    
    Node *cloneGraphRe(Node *node, MAP &map) {
        if (!node) return NULL;
        if (map.find(node) != map.end())
            return map[node];
        Node *newNode = new Node(node->label);
        map[node] = newNode;
        for (int i = 0; i < node->neighbors.size(); ++i)
            newNode->neighbors.push_back(cloneGraphRe(node->neighbors[i], map));
        return newNode;
    }
    
        //BFS
    Node *cloneGraph_2(Node *node) {
        if (!node) return NULL;
        queue<Node*> q;
        q.push(node);
        MAP map;
        map[node] = new Node(node->label);
        while (!q.empty())
        {
            Node *oriNode = q.front(); 
            q.pop();
            Node *newNode = map[oriNode];
            for (int i = 0; i < oriNode->neighbors.size(); ++i)
            {
                Node *oriNeighbor = oriNode->neighbors[i];
                if (map.find(oriNeighbor) != map.end()) {
                    newNode->neighbors.push_back(map[oriNeighbor]);
                    continue;
                }
                Node *newNeighbor = new Node(oriNeighbor->label);
                newNode->neighbors.push_back(newNeighbor);
                map[oriNeighbor] = newNeighbor;
                q.push(oriNeighbor);
            }
        }
        return map[node];
    }
};
