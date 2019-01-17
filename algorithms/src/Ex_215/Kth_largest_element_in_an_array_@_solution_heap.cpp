// references:
//      https://leetcode.com/articles/kth-largest-element-in-an-array/
//      https://stackoverflow.com/questions/2439283/how-can-i-create-min-stl-priority-queue


#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::priority_queue;

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        priority_queue<int, std::vector<int>, std::greater<>> minHeap;

        for (const int i : nums) {
            minHeap.push(i);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};


int main() {
    Solution s;
    vector<int> input;
    int k;

    input = vector<int> {3, 2, 1, 5, 6, 4};
    k = 2;
    std::cout << s.findKthLargest(input, k) << std::endl;       // 5

    input = vector<int> {3, 2, 3, 1, 2, 4, 5, 5, 6};
    k = 4;
    std::cout << s.findKthLargest(input, k) << std::endl;       // 4

    return 0;
}
