class Solution {
public:
    /*
     * @param : A string
     * @param : A string
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string S, string T) {
    	int n = S.length(), m = T.length();

		int ans = 1;
		for (int i = 1; i <= n; ++i)
		{
			int k = 0;
			while (k<i && k<m)
			{
				if (!is_substring(i-k-1,k+1,S,T))
					break;
				++k;
			}
			ans += k-1;
		}
		return ans;
    }

    bool is_substring(int st,int len,string &s,string &t)
    {
    	string cur = s.substr(st,len);
    	int idx = 0;
    	for (int i = 0; i < t.length(); ++i)
    	{
    		if (s[idx] == t[i])
    			++idx;
    		if (idx >= len)
    			break;
    	}
    	return (idx >= len);
    }
};
