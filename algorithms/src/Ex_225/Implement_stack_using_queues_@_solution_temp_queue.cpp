#include <iostream>
#include <queue>

using std::queue;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() = default;

    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        queue<int> tempQ2;

        while (!q1.empty() && q1.size() > 1) {
            tempQ2.push(q1.front());
            q1.pop();
        }
        int returnValue = q1.front();
        q1 = tempQ2;
        return returnValue;
    }

    /** Get the top element. */
    int top() {
        return q1.back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }

private:
    queue<int> q1;
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
