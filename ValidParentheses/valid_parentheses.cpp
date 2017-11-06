class Solution {
public:
    /*
     * @param s: A string
     * @return: whether the string is a valid parentheses
     */
    bool isValidParentheses(string &s) {
    	int n = s.length();
    	if (n==0)
    		return true;

    	char match[300];
    	match[')'] = '(';
    	match[']'] = '[';
    	match['}'] = '{';

    	stack<char> st;
    	st.push(s[0]);
    	for (int i = 1; i < n; ++i)
    	{
    		switch (s[i])
    		{
    			case '(':
    			case '[':
    			case '{':
    				st.push(s[i]);
    				break;
    			case ')':
    			case ']':
    			case '}':
    				if (st.empty() || st.top() != match[s[i]])
    					return false;
    				st.pop();
    		}
    	}

    	return st.empty();
    }
};
