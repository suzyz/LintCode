class Solution {
public:
    /*
     * @param s: A string
     * @param dict: A dictionary of words dict
     * @return: A boolean
     */
    bool wordBreak(string &s, unordered_set<string> &dict) {
    	int n = s.length();
    	bool f[n+2];
    	memset(f,0,sizeof(f));
    	f[0] = true;

    	int lim = 0;
    	for (unordered_set<string>::iterator i = dict.begin(); i != dict.end(); ++i)
    	{
    		if (*i.length() > lim)
    			lim = *i.length();
    	}
    	for (int i = 1; i <= n; ++i)
    	{
    		for (int j = 1; j <= i && j <= lim; ++j)
    			if (f[i-j])
	    		{
	    			string cur = s.substr(i-j,j);
	    			if (dict.count(cur))
	    			{
	    				f[i] = true;
	    				break;
	    			}
	    		}
    	}
    	return f[n];
    }
};
