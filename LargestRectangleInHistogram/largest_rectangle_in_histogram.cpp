class Solution {
public:
    /*
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
    	int n = height.size(), ans = 0;
        if (n==0)
            return 0;

        height.insert(height.begin(),0);
        height.push_back(0);
        n += 2;

        stack<int> st;
        st.push(0);
        for (int idx = 1; idx < n; ++idx)
        {
            if (height[st.top()] > height[idx])
            {
                int first = st.top();
                int last = first;
                while (!st.empty() && height[st.top()] > height[idx])
                {
                    first = st.top();
                    st.pop();
                    ans = max(ans,height[first] * (last - st.top()));
                }
            }
            st.push(idx);
        }
    	
    	return ans;
    }
};
