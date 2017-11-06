class Stack {
public:
    vector<int> st;
    /*
     * @param x: An integer
     * @return: nothing
     */
    void push(int x) {
        st.push_back(x);
    }

    /*
     * @return: nothing
     */
    void pop() {
        st.erase(st.end()-1);
    }

    /*
     * @return: An integer
     */
    int top() {
        return *st.rbegin();
    }

    /*
     * @return: True if the stack is empty
     */
    bool isEmpty() {
        return st.empty();
    }
};
