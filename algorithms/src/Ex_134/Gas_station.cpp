// references:
//      https://en.cppreference.com/w/cpp/algorithm/sort
//      https://www.geeksforgeeks.org/greedy-algorithms/


#include <iostream>
#include <vector>

using std::vector;
using std::pair;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        auto size = static_cast<int> (gas.size());
        if (size == 1) {
            if (cost[0] > gas[0]) {
                return -1;
            } else {
                return 0;
            }
        }

        vector<pair<int, double>> idxRatio;
        idxRatio.reserve(static_cast<unsigned long>(size));
        for (int i = 0; i < size; i++) {
            if (cost[i] == 0) {
                // if the cost is 0, then change it to 1 in order to calculate
                // the "gas/cost" ratio
                idxRatio.emplace_back(i, ((double) gas[i]) / 1);
            } else {
                idxRatio.emplace_back(i, ((double) gas[i]) / cost[i]);
            }
        }

        // for debugging
//        for (const pair<int, double> &p : idxRatio) {
//            std::cout << "["
//                      << p.first << "," << p.second
//                      << "]" << std::endl;
//        }

        // sort idxRatio based on the second value (average)
        struct {
            bool operator()(pair<int, double> a, pair<int, double> b) const {
                return a.second > b.second;
            }
        } customGreatThan;
        std::sort(idxRatio.begin(), idxRatio.end(), customGreatThan);

        // for debugging
//        for (const pair<int, double> &p : idxRatio) {
//            std::cout << "["
//                      << p.first << "," << p.second
//                      << "]" << std::endl;
//        }

        int returnValue = -1;
        // try from the index of the biggest ratio to the index of the smallest ratio
        for (int i = 0; i < size; i++) {
            int currIdx = idxRatio[i].first;
            int g = gas[currIdx] - cost[currIdx];   // gas left
            int p;  // position
            for (p = (currIdx + 1) % size; p != currIdx; p = (p + 1) % size) {
                g = g + gas[p] - cost[p];
                if (g < 0) {
                    // cannot move to the next station
                    break;
                }
            }
            if (p == currIdx) {
                return currIdx;
            }
        }

        return -1;
    }
};


int main() {
    Solution s;
    vector<int> gas;
    vector<int> cost;
    // gas[i]  means that you can add amount of gas[i] to the gas tank
    // cost[i] means that it needs amount of cost[i] to travel from station i to station i+1

    gas = vector<int> {1, 2, 3, 4, 5};
    cost = vector<int> {3, 4, 5, 1, 2};
    std::cout << s.canCompleteCircuit(gas, cost) << std::endl;      // 3

    gas = vector<int> {2, 3, 4};
    cost = vector<int> {3, 4, 3};
    std::cout << s.canCompleteCircuit(gas, cost) << std::endl;      // -1

    gas = vector<int> {2, 0, 1, 2, 3, 4, 0};
    cost = vector<int> {0, 1, 0, 0, 0, 0, 11};
    std::cout << s.canCompleteCircuit(gas, cost) << std::endl;      // 0

    gas = vector<int> {4};
    cost = vector<int> {5};
    std::cout << s.canCompleteCircuit(gas, cost) << std::endl;      // -1

    return 0;
}
