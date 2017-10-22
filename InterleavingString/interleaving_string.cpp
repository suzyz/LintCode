class Solution {
public:
    /*
     * @param s1: A string
     * @param s2: A string
     * @param s3: A string
     * @return: Determine whether s3 is formed by interleaving of s1 and s2
     */
    bool isInterleave(string &s1, string &s2, string &s3) {
    	int n1 = s1.length(), n2 = s2.length(), m = s3.length();
    	if (m != n1+n2)
    		return false;

    	bool f[m+2][n1+2];
    	memset(f,0,sizeof(f));
    	f[0][0] = true;
    	for (int i = 1; i <= m; ++i)
    	{
    		for (int j = 0; j <= i && j <= n1; ++j)
    		{
    			if (j>0 && s3[i-1] == s1[j-1])
    				f[i][j] |= f[i-1][j-1];
    			if (j<i && s3[i-1] == s2[i-j-1])
    				f[i][j] |= f[i-1][j];
    		}
    	}
    	return f[m][n1];
    }
};
