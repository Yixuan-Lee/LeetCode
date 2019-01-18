#include <iostream>
#include <stack>

using std::stack;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() = default;

    /** Push element x to the back of queue. */
    void push(int x) {
        if (topValue == -1) {
            topValue = x;
        }
        nums.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        stack<int> dummyQueue;
        while (!nums.empty()) {
            dummyQueue.push(nums.top());
            nums.pop();
        }
        int returnValue = dummyQueue.top();
        dummyQueue.pop();
        if (!dummyQueue.empty()) {
            topValue = dummyQueue.top();
        } else {
            topValue = -1;
        }

        // push all elements in dummyQueue back to nums
        while (!dummyQueue.empty()) {
            nums.push(dummyQueue.top());
            dummyQueue.pop();
        }
        return returnValue;
    }

    /** Get the front element. */
    int peek() {
        return topValue;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return nums.empty();
    }

private:
    stack<int> nums;
    int topValue = -1;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */


int main() {
    MyQueue queue;
    queue.push(1);
    queue.push(2);
    std::cout << queue.peek() << std::endl;     // 1
    std::cout << queue.pop() << std::endl;      // 1
    std::cout << queue.empty() << std::endl;    // 0

    return 0;
}
