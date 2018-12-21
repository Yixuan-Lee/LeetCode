// references:
//      book: Algorithms (4th edition), Robert Sedgewick, Kevin Wayne

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    void sortColors(vector<int> &nums) {
        if (nums.empty() || nums.size() == 1) {
            return;
        }

        // uses quick sort
        quickSort(nums, 0, static_cast<int> (nums.size() - 1));
    }

private:
    void quickSort(vector<int> &nums, int lo, int hi) {
        if (hi <= lo) {
            return;
        }
        int j = partition(nums, lo, hi);
        quickSort(nums, lo, j - 1);
        quickSort(nums, j + 1, hi);
    }

    int partition(vector<int> &nums, int lo, int hi) {
        int i = lo;
        int j = hi + 1;
        int v = nums[lo];
        while (true) {
            while (nums[++i] < v) {
                if (i == hi) {
                    break;
                }
            }
            while (nums[--j] > v) {
                if (j == lo) {
                    break;
                }
            }
            if (i >= j) {
                break;
            }
            std::swap(nums[i], nums[j]);
        }
        std::swap(nums[lo], nums[j]);
        return j;
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
    vector<int> nums {2, 0, 2, 1, 1, 0};
    s.sortColors(nums);
    std::cout << nums << std::endl;
    return 0;
}
