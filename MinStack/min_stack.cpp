class MinStack {
public:
    struct Node
    {
        int v,cur_min;
        Node(int v1,int min1)
        {
            v = v1;
            cur_min = min1;
        }
    };
    vector<Node> st;

    MinStack() {
    }

    void push(int number) {
        int pre_min = number;
        if (st.size())
            pre_min = st[st.size()-1].cur_min;

        st.push_back(Node(number,std::min(number,pre_min)));
    }

    int pop() {
        if (!st.size())
            return 0;
        
        int res = st[st.size()-1].v;
        st.erase(st.end()-1);
        return res;
    }

    int min() {
        if (!st.size())
            return 0;
        return st[st.size()-1].cur_min;
    }
};
