// references:
//      https://leetcode.com/submissions/detail/198428948/ (sample 4ms submission)


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int total = 0;      // total amount of gas of all stations
        int tank = 0;       // left gas
        int start = 0;      // start index of current trial
        for (int i = 0; i < gas.size(); i++) {
            int curr = gas[i] - cost[i];
            total += curr;
            tank += curr;
            if (tank < 0) {
                // if cannot move to the next position, re-start the trial from position i+1
                tank = 0;
                start = i + 1;
            }
        }
        return total >= 0 ? start : -1;
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
