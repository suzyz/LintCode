class Solution {
public:
    /*
     * @param : A string
     * @param : A string
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string S, string T) {
    	int n = S.length(), m = T.length();
        int f[m+2];
        memset(f,0,sizeof(f));
        f[0] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = min(m,i); j>= 1; --j)
                if (S[i-1] == T[j-1])
                    f[j] += f[j-1];

		return f[m];
    }
};
