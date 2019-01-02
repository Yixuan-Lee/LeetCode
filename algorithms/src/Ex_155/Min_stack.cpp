#include <iostream>
#include <vector>

using std::vector;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() = default;

    void push(int x) {
        if (x < min) {
            min = x;
        }
        stack.push_back(x);
    }

    void pop() {
        int top = stack.back();
        stack.pop_back();

        // re-calculate the min value
        if (top == min) {
            min = INT_MAX;
            for (const int &i : stack) {
                if (i < min) {
                    min = i;
                }
            }
        }
    }

    int top() {
        return stack.back();
    }

    int getMin() {
        return min;
    }

private:
    vector<int> stack;
    int min = INT_MAX;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */


int main() {
    MinStack obj;
    obj.push(-2);
    obj.push(0);
    obj.push(-3);
    std::cout << obj.getMin() << std::endl;
    obj.pop();
    std::cout << obj.top() << std::endl;
    std::cout << obj.getMin() << std::endl;

    return 0;
}
