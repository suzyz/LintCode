class Solution {
public:
    /*
     * @param s: a string
     * @param p: a string
     * @return: a list of index
     */
    vector<int> findAnagrams(string &s, string &p) {
    	int n = s.length(), m = p.length();
    	vector<int> res;
    	if (n < m)
    		return res;

    	int sum[26], target[26];
    	memset(sum,0,sizeof(sum));
    	memset(target,0,sizeof(target));

    	for (int i = 0; i < m; ++i)
    	{
    		++target[p[i]-'a'];
    		++sum[s[i]-'a'];
    	}

    	for (int i = m-1; i < n; ++i)
    	{
    		if (memcmp(target,sum,sizeof(sum)) == 0)
    			res.push_back(i-m+1);

    		if (i == n-1)
    			break;

    		++sum[s[i+1]-'a'];
    		--sum[s[i-m+1]-'a'];
    	}

    	return res;
    }
};
