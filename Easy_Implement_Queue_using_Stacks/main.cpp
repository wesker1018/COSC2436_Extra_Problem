#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> inStack, outStack;

    // Move elements from inStack to outStack if needed
    void transfer() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        transfer();
        int val = outStack.top();
        outStack.pop();
        return val;
    }

    int peek() {
        transfer();
        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};

int main() {
    MyQueue myQueue;
    myQueue.push(1); // queue: [1]
    myQueue.push(2); // queue: [1, 2]
    cout << myQueue.peek() << endl; // return 1
    cout << myQueue.pop() << endl;  // return 1, queue: [2]
    cout << boolalpha << myQueue.empty() << endl; // return false
    return 0;
}
