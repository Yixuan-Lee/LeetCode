// references:
//      https://leetcode.com/problems/clone-graph/discuss/42309/Depth-First-Simple-Java-Solution
//      https://www.programcreek.com/2012/12/leetcode-clone-graph-java/


#include <iostream>
#include <vector>
#include <map>
#include <queue>

using std::vector;
using std::map;
using std::queue;

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

        // use a queue to do breadth-first traversal
        queue<UndirectedGraphNode *> que;
        // use a map to store the visited nodes
        // (that is, the mapping between original node and copied node)
        map<UndirectedGraphNode *, UndirectedGraphNode *> hash;

        // create a new node,
        // and push the original node to the queue
        // then add a mapping in the hash map
        auto *newNode = new UndirectedGraphNode(node->label);
        que.push(node);
        hash.insert(std::make_pair(node, newNode));

        // clone the graph
        while (!que.empty()) {
            UndirectedGraphNode *curr = que.front();
            que.pop();
            vector<UndirectedGraphNode *> currNeighbors = curr->neighbors;

            for (UndirectedGraphNode *u : currNeighbors) {
                if (hash.find(u) == hash.end()) {
                    // if it is relatively a new node, create a new node
                    auto *copy = new UndirectedGraphNode(u->label);
                    // then add a mapping between the original node and the copied node
                    hash.insert(std::make_pair(u, copy));
                    // then add the new node to neighbor list of copied node corresponding to the curr node
                    hash[curr]->neighbors.push_back(copy);
                    // then push the visited node u to the queue
                    que.push(u);
                } else {
                    // if curr exists in the hash (already visited before)
                    // then add the node u to neighbor list of copied node corresponding to the curr node
                    hash[curr]->neighbors.push_back(hash[u]);
                }
            }
        }

        return newNode;
    }
};


int main() {
    Solution s;

    return 0;
}
