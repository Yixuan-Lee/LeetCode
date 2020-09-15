#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::pair;
using std::vector;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>> &edges) {
        map<int, int> hash;
        for (int i = 0; i < n; i++) {
            hash[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            for (pair<int, int> e : edges) {
                int height = 0;
                if (e.first == i) {
                    height = getHeight(edges, e, 1, hash[i]);
                } else if (e.second == i) {
                    pair<int, int> newE;
                    newE.first = e.second;
                    newE.second = e.first;
                    height = getHeight(edges, newE, 1, hash[i]);
                }
                if (height > hash[e.first]) {
                    hash[e.first] = height;
                }
            }
        }

        return ans;
    }

private:
    vector<int> ans;

    int getHeight(const vector<pair<int, int>> &edges, pair<int, int> edge,
            int height, int maxHeight) {
        for (pair<int, int> e : edges) {
            if (edge.second == e.first || edge.second == e.second) {
                if (edge.second == e.first && edge.first == e.second) {
                    // avoid cycle
                    continue;
                }
                if (e == edge) {
                    // avoid cycle
                    continue;
                }

                pair<int, int> next;
                if (e.second == edge.second) {
                    next.first = e.second;
                    next.second = e.first;
                } else {
                    next = e;
                }
                height = getHeight(edges, next, height + 1, maxHeight);
            }
        }

        if (height > maxHeight) {
            maxHeight = height;
        }
        return maxHeight;
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
    int n;
    vector<pair<int, int>> edges;

    n = 6;
    edges.emplace_back(0, 3);
    edges.emplace_back(1, 3);
    edges.emplace_back(2, 3);
    edges.emplace_back(4, 3);
    edges.emplace_back(5, 4);
    std::cout << s.findMinHeightTrees(n, edges) << std::endl;   // [3, 4]

    n = 4;
    edges.emplace_back(1, 0);
    edges.emplace_back(1, 2);
    edges.emplace_back(1, 3);
    std::cout << s.findMinHeightTrees(n, edges) << std::endl;   // [1]

    return 0;
}

