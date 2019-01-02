// references:
//      https://leetcode.com/problems/clone-graph/discuss/42309/Depth-First-Simple-Java-Solution
//      https://www.programcreek.com/2012/12/leetcode-clone-graph-java/


#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>

using std::vector;
using std::map;
using std::queue;
using std::set;

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

        queue<UndirectedGraphNode *> que;
        // use a map to store the mapping between original node and copied node
        map<UndirectedGraphNode *, UndirectedGraphNode *> hash;

        que.push(node);
        while (!que.empty()) {
            // get nodes from the front of the queue
            UndirectedGraphNode *front = que.front();
            que.pop();

            // create a copied node and insert the mapping in the hash
            auto *newNode = new UndirectedGraphNode(front->label);
            hash.insert(std::make_pair(front, newNode));

            // push all neighbors of front's neighbors to the que
            for (UndirectedGraphNode *u : front->neighbors) {
                if (hash.find(u) == hash.end()) {
                    que.push(u);
                }
            }
        }

        que.push(node);
        set<UndirectedGraphNode *> set;     // avoid repetitive nodes
        set.insert(node);

        while (!que.empty()) {
            // get nodes from the front of the queue
            UndirectedGraphNode *front = que.front();
            que.pop();

            for (UndirectedGraphNode *u : front->neighbors) {
                if (set.find(u) == set.end()) {
                    // if u is relatively a new node, then add it to the queue
                    // and the set
                    que.push(u);
                    set.insert(u);
                }
                // add copied node of u to the neighbor list of copied node of front
                hash[front]->neighbors.push_back(hash[u]);
            }
        }

        return hash[node];
    }
};


int main() {
    Solution s;

    return 0;
}
