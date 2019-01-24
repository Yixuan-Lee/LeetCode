#include <iostream>
#include <vector>
#include <unordered_set>

using std::vector;
using std::pair;
using std::unordered_set;

class Solution {
public:
    vector<int> findOrder(int numCourses,
            vector<pair<int, int>> &prerequisites) {
        // build graph
        //      first: course code i
        //      second: course i's prerequisites course code
        // usage:
        //      indicate if you want to take course i, you have to take all
        //      its prerequisites in course[i]
        vector<unordered_set<int>> graph_course2prerequisites = makeGraph(
                numCourses, prerequisites);

        // build graph
        //      first: prerequisites course codes of course i
        //      second: course code i
        // usage:
        //      indicate after you take course i, you can take courses in
        //      course[i] which prerequisites include course i
        vector<unordered_set<int>> graph_prerequsites2course = makeGraph2(
                numCourses, prerequisites);

        // record the visited nodes in the current DFS visit
        vector<bool> onPath(static_cast<unsigned long> (numCourses), false);
        // record the all visited nodes
        vector<bool> visited(static_cast<unsigned long> (numCourses), false);
        // returned vector
        vector<int> ans;

        // push all courses that not appear in prerequisites to ans
        for (const pair<int, int> &p : prerequisites) {
            visited[p.first] = true;
            visited[p.second] = true;
        }
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == false) {
                ans.push_back(i);
                visited[i] = true;
            } else {
                visited[i] = false;
            }
        }
        if (ans.size() == numCourses) {
            return ans;
        }


        for (int i = 0; i < numCourses; i++) {
            if (allPrerequisitesVisited(graph_course2prerequisites, i,
                    onPath)) {
                ans.push_back(i);
                dfs(graph_course2prerequisites, graph_prerequsites2course, i,
                        onPath, ans, numCourses);

                if (allInAns(ans, numCourses)) {
                    break;
                }
                ans.pop_back();
                onPath[i] = false;
            }
        }

        return ans;
    }

private:
    vector<unordered_set<int>> makeGraph(int numCourses,
            vector<pair<int, int>> &prerequisites) {
        vector<unordered_set<int>> graph(
                static_cast<unsigned long> (numCourses));
        for (const pair<int, int> &pre : prerequisites) {
            // pre.first's prerequisite course(s) is pre.second
            graph[pre.first].insert(pre.second);
        }

        return graph;
    }

    vector<unordered_set<int>> makeGraph2(int numCourses,
            vector<pair<int, int>> &prerequisites) {
        vector<unordered_set<int>> graph(
                static_cast<unsigned long> (numCourses));
        for (const pair<int, int> &pre : prerequisites) {
            // pre.first's prerequisite course(s) is pre.second
            graph[pre.second].insert(pre.first);
        }

        return graph;
    }

    void dfs(const vector<unordered_set<int>> &graph_course2prerequisites,
            const vector<unordered_set<int>> &graph_prerequisites2course,
            int node, vector<bool> &onPath, vector<int> &ans,
            int numCourses) {

        if (onPath[node]) {
            return;
        }
        onPath[node] = true;
        if (allInAns(ans, numCourses)) {
            return;
        }

        for (int neighbor : graph_prerequisites2course[node]) {
            if (allPrerequisitesVisited(graph_course2prerequisites, neighbor,
                    onPath)) {
                ans.push_back(neighbor);
                dfs(graph_course2prerequisites, graph_prerequisites2course,
                        neighbor, onPath, ans, numCourses);
//                ans.pop_back();
//                onPath[neighbor] = false;
            } else {
                for (int course : graph_course2prerequisites[neighbor]) {
                    if (allPrerequisitesVisited(graph_course2prerequisites,
                            course, onPath)) {
                        ans.push_back(course);
                        dfs(graph_course2prerequisites,
                                graph_prerequisites2course, course, onPath,
                                ans,
                                numCourses);
                    }
                }
            }

            if (allInAns(ans, numCourses)) {
                return;
            }
        }
    }

    bool allInAns(const vector<int> &ans, int numCourses) {
        return ans.size() == numCourses;
    }

    bool allPrerequisitesVisited(const vector<unordered_set<int>> &graph,
            int node, const vector<bool> &visited) {
        for (int pre : graph[node]) {
            if (!visited[pre]) {
                return false;
            }
        }

        return true;
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
