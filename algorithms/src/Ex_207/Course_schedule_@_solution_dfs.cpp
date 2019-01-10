// references:
//      https://leetcode.com/problems/course-schedule/discuss/58509/18-22-lines-C%2B%2B-BFSDFS-Solutions  (great article)


#include <iostream>
#include <vector>
#include <unordered_set>

using std::unordered_set;
using std::vector;
using std::pair;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
        // graph[i]: nodes that contributes in-degree of node i
        vector<unordered_set<int>> graph = makeGraph(numCourses,
                prerequisites);
        // record the visited nodes in the current DFS visit
        vector<bool> onPath(static_cast<unsigned long> (numCourses), false);
        // record the all visited nodes
        vector<bool> visited(static_cast<unsigned long> (numCourses), false);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && dfsIncludeCycle(graph, i, onPath, visited)) {
                return false;
            }
        }

        return true;
    }

private:
    vector<unordered_set<int>> makeGraph(int numCourses,
            vector<pair<int, int>> &prerequisites) {
        vector<unordered_set<int>> graph(
                static_cast<unsigned long>(numCourses));
        for (const pair<int, int> &pre : prerequisites) {
            // graph[pre.second] means all neighbors of node pre.second
            graph[pre.second].insert(pre.first);
        }

        return graph;
    }

    /**
     * determine if there is a cycle in the graph based on DFS visit
     *
     * @param graph graph
     * @param node  current visited node
     * @param onPath
     * @param visited
     * @return return true if the graph has cycle, otherwise return false
     */
    bool dfsIncludeCycle(const vector<unordered_set<int>> &graph, int node,
            vector<bool> &onPath, vector<bool> &visited) {
        if (onPath[node]) {
            // if it meets a node which was visited in the current process of dfs visit,
            // then it means a cycle is detected, so it is not a DAG (directed acyclic graph)
            return true;
        }

        onPath[node] = true;
        visited[node] = true;
        for (int neighbor : graph[node]) {
            if (dfsIncludeCycle(graph, neighbor, onPath, visited)) {
                // continue to test a cycle, return true if there is
                return true;
            }
        }
        onPath[node] = false;   // reset the node to unvisited for current dfs visit

        return false;   // graph has no cycle
    }
};


int main() {
    Solution s;
    vector<pair<int, int>> prerequisites;
    int numCourses;

    numCourses = 2;
    prerequisites = vector<pair<int, int>> {std::make_pair(1, 0)};
    std::cout << s.canFinish(numCourses, prerequisites) << std::endl;   // 1

    numCourses = 2;
    prerequisites = vector<pair<int, int>> {
            std::make_pair(1, 0), std::make_pair(0, 1)
    };
    std::cout << s.canFinish(numCourses, prerequisites) << std::endl;   // 0

    numCourses = 4;
    prerequisites = vector<pair<int, int>> {
            std::make_pair(0, 1), std::make_pair(1, 2),
            std::make_pair(2, 3), std::make_pair(3, 1)
    };
    std::cout << s.canFinish(numCourses, prerequisites) << std::endl;   // 0

    numCourses = 7;
    prerequisites = vector<pair<int, int>> {
            std::make_pair(0, 1), std::make_pair(1, 2),
            std::make_pair(2, 3), std::make_pair(4, 5),
            std::make_pair(5, 3), std::make_pair(3, 6)
    };
    std::cout << s.canFinish(numCourses, prerequisites) << std::endl;   // 1

    numCourses = 6;
    prerequisites = vector<pair<int, int>> {
            std::make_pair(0, 1), std::make_pair(0, 2),
            std::make_pair(1, 3), std::make_pair(2, 3),
            std::make_pair(3, 4), std::make_pair(4, 5)
    };
    std::cout << s.canFinish(numCourses, prerequisites) << std::endl;   // 1

    numCourses = 3;
    prerequisites = vector<pair<int, int>> {
            std::make_pair(1, 0), std::make_pair(1, 2),
            std::make_pair(0, 1)
    };
    std::cout << s.canFinish(numCourses, prerequisites) << std::endl;   // 0

    return 0;
}
