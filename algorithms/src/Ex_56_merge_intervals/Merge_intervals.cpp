// references:
//      https://www.geeksforgeeks.org/sorting-vector-of-pairs-in-c-set-1-sort-by-first-and-second/


#include <iostream>
#include <vector>

using std::vector;

struct Interval {
    int start;
    int end;

    explicit Interval() : start(0), end(0) {}

    explicit Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.empty()) {
            return intervals;
        }

        // use sort() function to sort intervals by first value of intervals
        std::sort(intervals.begin(), intervals.end(), sortByFirst);

        vector<Interval> res;
        res.push_back(intervals[0]);
        int size = 1;
        for (const Interval &i : intervals) {
            if (i.start <= res[size - 1].end) {
                // if current interval's left value is smaller or equal to
                // right value of the last interval in res, then merge two
                res[size - 1].end = std::max(res[size - 1].end, i.end);
            } else {
                // if current interval's left value is bigger than
                // right value of the last interval in res, then insert i
                res.push_back(i);
                size++;
            }
        }

        return res;
    }

private:
    static bool sortByFirst(const Interval &i1, const Interval &i2) {
        return i1.start < i2.start;
    }
};


int main() {
    Solution s;
    Interval i1(1, 4);
    Interval i2(2, 3);
//    Interval i3(2, 6);
//    Interval i4(15, 18);

    vector<Interval> input {i1, i2};
    vector<Interval> res = s.merge(input);
    std::cout << "[";
    for (const Interval &i : res) {
        std::cout << "[" << i.start << ", " << i.end << "], ";
    }
    std::cout << "]" << std::endl;
    return 0;
}
