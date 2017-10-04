class Solution {
public:
    /*
     * @param s: a string,  encoded message
     * @return: an integer, the number of ways decoding
     */
    int numDecodings(string &s) {
    	int n = s.length();

    	for (string::iterator it = s.begin(); it != s.end(); )
    		if (*it == ' ')
    		{
    			--n;
    			it = s.erase(it);
    		}
    		else
    		{
    			if (*it < '0' || *it > '9')
    				return 0;

    			++it;
    		}

    	if (n==0 || s[0] == '0')
    		return 0;

    	int f[n];
    	f[0] = 1;
    	for (int i = 1; i < n; ++i)
    	{
    		if (s[i] == '0')
    			f[i] = 0;
    		else
    			f[i] = f[i-1];

    		if (s[i-1] == '1' || s[i-1] == '2')
    		{
    			int tmp = (s[i-1] - '0') * 10 + s[i] - '0';
    			if (tmp>=10 && tmp<=26)
    			{
    				if (i==1)
    					++f[i];
    				else
    					f[i] += f[i-2];
    			}
    		}
    	}
    	return f[n-1];
    }
};
