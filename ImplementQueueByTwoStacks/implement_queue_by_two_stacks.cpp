class MyQueue {
public:
    stack<int> stack1;
    stack<int> stack2;
    MyQueue() {
        // do intialization if necessary

    }

    /*
     * @param element: An integer
     * @return: nothing
     */
    void push(int element) {
        stack1.push(element);
    }

    /*
     * @return: An integer
     */
    int pop() {
        if (stack2.empty())
            invert();
        
        int res = stack2.top();
        stack2.pop();
        return res;
    }

    /*
     * @return: An integer
     */
    int top() {
        if (stack2.empty())
            invert();
        return stack2.top();
    }

    void invert()
    {
        while (!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
};
