#include <iostream>
#include <vector>

using std::vector;

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
    Data *data;
public:
    Iterator(const vector<int> &nums);

    Iterator(const Iterator &iter);

    virtual ~Iterator();

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        if (Iterator::hasNext()) {
            curr = Iterator::next();
            hasCurr = true;
        } else {
            hasCurr = false;
        }
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return curr;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int returnedValue = this->curr;
        if (Iterator::hasNext()) {
            this->curr = Iterator::next();
        } else {
            hasCurr = false;
        }
        return returnedValue;;
    }

    bool hasNext() const {
        return Iterator::hasNext() || hasCurr;
    }

private:
    int curr;
    bool hasCurr;
};


int main() {
    PeekingIterator pi(vector<int> {});

    return 0;
}
