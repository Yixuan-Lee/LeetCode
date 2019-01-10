// references:
//      How a graph is represented: https://www.khanacademy.org/computing/computer-science/algorithms/graph-representation/a/representing-graphs
//      Graph topological sort using dfs: https://www.youtube.com/watch?v=n_yl2a6n7nM


#include <iostream>
#include <vector>

using std::vector;
using std::pair;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {

    }

    int *dfsTopsort() {
        bool *visited = new bool[adjLists.size()];
        int *topnum = new int[adjLists.size()];
        int n = static_cast<int> (adjLists.size() - 1);
        for (int v = 0; v < adjLists.size(); v++) {
            if (!visited[v]) {
                n = dfsTopsort(v, visited, topnum, n);
            }
        }
        return topnum;
    }

private:
    class Neighbor {
    public:
        int vertexNum;
        Neighbor *next;

        explicit Neighbor(int vnum, Neighbor *nbr) : vertexNum(vnum),
                                                     next(nbr) {
        }
    };

    class Vertex {
    public:
        int name;
        Neighbor *adjList;

        explicit Vertex(int n, Neighbor *neighbors) : name(n),
                                                      adjList(neighbors) {
        }
    };

    vector<Vertex> adjLists;

    int dfsTopsort(int v, bool visited[], int topnum[], int n) {
        visited[v] = true;
        for (Neighbor *nbr = adjLists[v].adjList;
             nbr != nullptr; nbr = nbr->next) {
            if (!visited[nbr->vertexNum]) {
                n = dfsTopsort(nbr->vertexNum, visited, topnum, n);
            }
        }
        // about to back up to previous vertex
        topnum[n] = v;  // assign top num
        return n - 1;   // return to caller
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

    return 0;
}
