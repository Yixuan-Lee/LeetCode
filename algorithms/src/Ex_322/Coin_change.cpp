// references:
//      https://stackoverflow.com/questions/9025084/sorting-a-vector-in-descending-order


#include <iostream>
#include <vector>

using std::vector;

struct greater {
    template<class T>
    bool operator()(T const &a, T const &b) const {
        return a > b;
    }
};

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        if (coins.empty()) {
            return -1;
        }

        std::sort(coins.begin(), coins.end(), greater());

        vector<int> change;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = 0; ; j++) {
                
            }
        }

    }
};


int main() {
    Solution s;

    return 0;
}
