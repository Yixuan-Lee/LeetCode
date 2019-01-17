// references:
//      https://stackoverflow.com/questions/9025084/sorting-a-vector-in-descending-order


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        struct {
            bool operator()(const int &a, const int &b) const {
                return a > b;
            }
        } customGreaterThan;
        // sort nums in descending order
        std::sort(nums.begin(), nums.end(), customGreaterThan);

        return nums[k - 1];
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
