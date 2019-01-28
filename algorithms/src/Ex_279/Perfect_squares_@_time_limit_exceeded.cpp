#include <iostream>
#include <cmath>
#include <vector>

using std::vector;

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

class Solution {
public:
    int numSquares(int n) {
        if (n == 0) {
            return 0;
        }

        auto maxSqrt = static_cast<int> (floor(sqrt(n)));
//        std::cout << maxSqrt << std::endl;
        vector<int> square;
        for (int i = 1; i <= maxSqrt; i++) {
            square.push_back(i * i);
        }
//        std::cout << square << std::endl;

        int count = INT_MAX;
        int per = 0;

        setPerfectSquares(square, n, count, per);

        return count;
    }

private:
    void setPerfectSquares(const vector<int> &square, int n, int &count,
            int &per) {
        if (n < 0) {
            return;
        }
        if (n == 0 && per < count) {
            count = per;
            return;
        }
        for (int i = static_cast<int> (square.size() - 1); i >= 0; i--) {
            n -= square[i];
            per++;
            setPerfectSquares(square, n, count, per);
            per--;
            n += square[i];
        }
    }
};


int main() {
    Solution s;
    int n;

    n = 12;
    std::cout << s.numSquares(n) << std::endl;      // 3

    n = 13;
    std::cout << s.numSquares(n) << std::endl;      // 2

    n = 26;
    std::cout << s.numSquares(n) << std::endl;      // 2

    n = 51;
    std::cout << s.numSquares(n) << std::endl;      // 3

    return 0;
}
