#include <iostream>
#include <deque>

using std::deque;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() = default;

    /** Push element x onto stack. */
    void push(int x) {
        dq.push_back(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int returnVal = dq.back();
        dq.pop_back();
        return returnVal;
    }

    /** Get the top element. */
    int top() {
        return dq.back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return dq.empty();
    }

private:
    deque<int> dq;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */


int main() {
    MyStack stack;
    stack.push(1);
    stack.push(2);
    std::cout << stack.top() << std::endl;      // 2
    std::cout << stack.pop() << std::endl;      // 2
    std::cout << stack.empty() << std::endl;    // 0

    return 0;
}