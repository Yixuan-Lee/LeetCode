#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }

        auto size = static_cast<int> (nums.size());
        // record the maximum product for each num
        vector<int> maximum(static_cast<unsigned long> (size), 0);
        // record the minimum product for each num
        vector<int> minimum(static_cast<unsigned long> (size), 0);

        int currIdx = 0;
        nums[currIdx] > 0 ? maximum[currIdx] = nums[currIdx]
                          : minimum[currIdx] = nums[currIdx];
        int max = nums[currIdx];
        currIdx++;

        while (currIdx < size) {
            int product1 = maximum[currIdx - 1] * nums[currIdx];
            int product2 = minimum[currIdx - 1] * nums[currIdx];

            maximum[currIdx] = std::max(std::max(product1, product2),
                    nums[currIdx]);
            minimum[currIdx] = std::min(std::min(product1, product2),
                    nums[currIdx]);
            if (maximum[currIdx] > max) {
                max = maximum[currIdx];
            }
            currIdx++;
        }

        return max;
    }
};


int main() {
    Solution s;
    vector<int> input;

    input = vector<int> {2, 3, -2, 4};
    std::cout << s.maxProduct(input) << std::endl;

    input = vector<int> {-2, 0, -1};
    std::cout << s.maxProduct(input) << std::endl;

    input = vector<int> {-2, -3, -1};
    std::cout << s.maxProduct(input) << std::endl;

    input = vector<int> {-2, 33, 100, -1};
    std::cout << s.maxProduct(input) << std::endl;

    input = vector<int> {-2, 3};
    std::cout << s.maxProduct(input) << std::endl;

    input = vector<int> {2, -1, 1, 1};
    std::cout << s.maxProduct(input) << std::endl;

    return 0;
}
