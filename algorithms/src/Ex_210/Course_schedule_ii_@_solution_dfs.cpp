// references:
//      https://leetcode.com/articles/course-schedule-ii/

// comments on the question:
//      1. [a, b] means that course b is a prerequisite for the course a,
//         which can be represented as a direct edge b->a in the graph
//      2. since as the question mentioned that an ordering may not always be
//         possible, so it means there may be a cycle in the graph that makes
//         some course unreachable


#include <iostream>
#include <vector>
#include <map>
#include <list>

using std::vector;
using std::pair;
using std::map;
using std::list;

class Solution {
public:
    vector<int> findOrder(int numCourses,
            vector<pair<int, int>> &prerequisites) {
        this->init(numCourses);

        // create the adjacency list representation of the graph
        makeGraph(adjacentList, prerequisites);

        for (int i = 0; i < numCourses; i++) {
            if (color[i] == Solution::WHITE) {
                dfs(i);
            }
        }

        vector<int> ans;
        if (isPossible) {
            while (!topologicalOrder.empty()) {
                ans.push_back(topologicalOrder.back());
                topologicalOrder.pop_back();
            }
        }

        return ans;
    }

private:
    const static int WHITE = 1;
    const static int GRAY = 2;
    const static int BLACK = 3;

    bool isPossible;
    map<int, int> color;
    map<int, list<int>> adjacentList;
    list<int> topologicalOrder;

    void init(int numCourses) {
        // seriously, when using map/list/vector alike build-in data structure
        // don't forget to initialize first, otherwise, there may be some
        // older values in the data structure which may make the result
        // incorrect!

        isPossible = true;

        // at the beginning, set all vertices are white
        for (int i = 0; i < numCourses; i++) {
            color[i] = Solution::WHITE;
        }

        // initialize the adjacentList
        for (int i = 0; i < numCourses; i++) {
            adjacentList[i] = list<int> {};
        }

        // initialize the topologicalOrder
        topologicalOrder = list<int> {};
    }

    void dfs(int node) {
        // return if there is a cycle
        if (!this->isPossible) {
            return;
        }

        // start the recursion
        this->color[node] = Solution::GRAY;

        // traverse the neighboring vertices
        for (int neighbor : adjacentList[node]) {
            // print the neighbors of vertex node (for debugging)
//            std::cout << "adjacentList[" << node << "]: {";
//            for (int i : adjacentList[node]) {
//                std::cout << i << ",";
//            }
//            std::cout << "}\n";

            if (color[neighbor] == Solution::WHITE) {
                dfs(neighbor);
            } else if (color[neighbor] == Solution::GRAY) {
                // an edge to a GRAY vertex means a cycle
                isPossible = false;
            }
        }

        // if all its neighbors are black already, then mark it as black
        color[node] = Solution::BLACK;
        topologicalOrder.push_back(node);
    }

    void makeGraph(map<int, list<int>> &adjacentList,
            const vector<pair<int, int>> &prerequisites) {
        for (auto &prerequisite : prerequisites) {
            int dest = prerequisite.first;
            int src = prerequisite.second;
            adjacentList[src].push_back(dest);
            // for debugging
//            for (int i : adjacentList[src]) {
//                std::cout << i << ",";
//            }
        }
    }
};


// declare a template for overloading the << operator for vector<T>
template<typename T>
std::ostream &operator<<(std::ostream &output, const vector<T> &v) {
    std::cout << "[";
    for (auto &i : v) {
        std::cout << i << ",";
    }
    std::cout << "]" << std::endl;
    return output;
}

int main() {
    Solution s;
    vector<pair<int, int>> prerequisites;
    int numCourses;

    numCourses = 2;
    prerequisites = vector<pair<int, int>> {std::make_pair(1, 0)};
    std::cout << s.findOrder(numCourses, prerequisites)
              << std::endl;   // [0, 1]

    numCourses = 2;
    prerequisites = vector<pair<int, int>> {
            std::make_pair(1, 0), std::make_pair(0, 1)
    };
    std::cout << s.findOrder(numCourses, prerequisites)
              << std::endl;   // []

    numCourses = 4;
    prerequisites = vector<pair<int, int>> {
            std::make_pair(0, 1), std::make_pair(1, 2),
            std::make_pair(2, 3), std::make_pair(3, 1)
    };
    std::cout << s.findOrder(numCourses, prerequisites)
              << std::endl;   // []

    numCourses = 7;
    prerequisites = vector<pair<int, int>> {
            std::make_pair(0, 1), std::make_pair(1, 2),
            std::make_pair(2, 3), std::make_pair(4, 5),
            std::make_pair(5, 3), std::make_pair(3, 6)
    };
    std::cout << s.findOrder(numCourses, prerequisites)
              << std::endl;   // [6, 3, 5, 4, 2, 1, 0]

    numCourses = 6;
    prerequisites = vector<pair<int, int>> {
            std::make_pair(0, 1), std::make_pair(0, 2),
            std::make_pair(1, 3), std::make_pair(2, 3),
            std::make_pair(3, 4), std::make_pair(4, 5)
    };
    std::cout << s.findOrder(numCourses, prerequisites)
              << std::endl;   // [5, 4, 3, 2, 1, 0]

    numCourses = 3;
    prerequisites = vector<pair<int, int>> {
            std::make_pair(1, 0), std::make_pair(1, 2),
            std::make_pair(0, 1)
    };
    std::cout << s.findOrder(numCourses, prerequisites)
              << std::endl;   // []

    numCourses = 2;
    prerequisites = vector<pair<int, int>> {};
    std::cout << s.findOrder(numCourses, prerequisites)
              << std::endl;   // [1, 0]

    numCourses = 4;
    prerequisites = vector<pair<int, int>> {
            std::make_pair(1, 0), std::make_pair(2, 0),
            std::make_pair(3, 1), std::make_pair(3, 2)
    };
    std::cout << s.findOrder(numCourses, prerequisites)
              << std::endl;   // [0, 2, 1, 3]

    numCourses = 3;
    prerequisites = vector<pair<int, int>> {};
    std::cout << s.findOrder(numCourses, prerequisites)
              << std::endl;   // [2, 1, 0]

    numCourses = 3;
    prerequisites = vector<pair<int, int>> {std::make_pair(1, 0)};
    std::cout << s.findOrder(numCourses, prerequisites)
              << std::endl;   // [2, 0, 1]

    numCourses = 3;
    prerequisites = vector<pair<int, int>> {
            std::make_pair(2, 0), std::make_pair(2, 1)
    };
    std::cout << s.findOrder(numCourses, prerequisites)
              << std::endl;   // [1, 0, 2]

    return 0;
}
