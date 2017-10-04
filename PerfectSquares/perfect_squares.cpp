class Solution {
public:
    /*
     * @param n: a positive integer
     * @return: An integer
     */
    int numSquares(int n) {
        int lim = sqrt(n);
        if (lim * lim < n)
            ++lim;
            
        int f[n+1];
        
        for (int i = 0; i <= n; ++i)
            f[i] = i;
        
        for (int i = 2; i <= lim; ++i)
        {
            int sq = i*i;
            for (int j = sq; j <= n; ++j)
                if (f[j] > f[j-sq] + 1)
                    f[j] = f[j-sq] + 1;
        }
        return f[n];
    }
};
