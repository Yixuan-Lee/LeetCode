// references:
//      https://leetcode.com/problems/course-schedule/discuss/58509/18-22-lines-C%2B%2B-BFSDFS-Solutions


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
        // degrees[i]: how many degrees the node i contributes
        vector<int> degrees = computeInDegree(graph);
        // record the node that is tested to avoid redundant iterations (by user myih's comment)
        vector<bool> visited(static_cast<unsigned long> (numCourses), false);

        for (int i = 0; i < numCourses; i++) {
            if (visited[i]) {
                // if we have already visited node i and reduce its neighbors' in-degree,
                // then we test the next node i + 1
                continue;
            }
            int j;
            for (j = 0; j < numCourses; j++) {
                if (degrees[j] == 0) {
                    // found one node which in-degree is 0
                    break;
                }
            }
            if (j == numCourses) {
                // if all nodes' in-degree are not 0,
                // then there must be a cycle in the graph
                return false;
            }
            // set in-degree of node j to be -1
            degrees[j] = -1;
            visited[j] = true;
            // then reduce the in-degrees of j's neighbors by 1
            for (int neighbor : graph[j]) {
                degrees[neighbor]--;
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

    vector<int> computeInDegree(vector<unordered_set<int>> &graph) {
        vector<int> degrees(graph.size(), 0);
//        int i = 0;
        for (const unordered_set<int> &neighbors : graph) {
            for (int neighbor : neighbors) {
                degrees[neighbor]++;
            }
//            degrees[i++] = static_cast<int> (neighbors.size());
        }

        return degrees;
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
