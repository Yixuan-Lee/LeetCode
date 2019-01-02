// references:
//      https://leetcode.com/problems/clone-graph/discuss/42309/Depth-First-Simple-Java-Solution


#include <iostream>
#include <vector>
#include <map>

using std::vector;
using std::map;

struct UndirectedGraphNode {
    int label;  // label is unique
    vector<UndirectedGraphNode *> neighbors;

    explicit UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr) {
            return nullptr;
        }

        UndirectedGraphNode *itOldGraph = node;

        // if the node exists in the hash, then returns the node
        if (hash.find(itOldGraph->label) != hash.end()) {
            return hash[itOldGraph->label];
        }

        // if the node is a new node, then create it, and add it to the hash
        auto newNode = new UndirectedGraphNode(itOldGraph->label);
        hash.insert(std::make_pair(newNode->label, newNode));

        // traverse all its neighbors, and add them to newNode->neighbors
        for (UndirectedGraphNode *u : itOldGraph->neighbors) {
            newNode->neighbors.push_back(cloneGraph(u));
        }
        return newNode;
    }

private:
    // stores the mapping of node's label and the node
    map<int, UndirectedGraphNode *> hash;
};


int main() {
    Solution s;

    return 0;
}
