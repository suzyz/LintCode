class Solution {
public:
    /*
     * @param K: An integer
     * @param prices: An integer array
     * @return: Maximum profit
     */
    int maxProfit(int K, vector<int> &prices) {
        int n = prices.size(), res = 0;

        K = min(n,2*K);

        int f[2][K+2], g[2][K+2];

        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));

        bool flag = 0;

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= min(i,K); ++j)
            {
                if (j%2)
                {
                    g[flag][j] = f[1-flag][j-1] - prices[i-1];
                    if (j < i)
                        g[flag][j] = max(g[flag][j],g[1-flag][j]);
                }
                else
                {
                    f[flag][j] = g[1-flag][j-1] + prices[i-1];

                    if (j < i) 
                        f[flag][j] = max(f[flag][j],f[1-flag][j]);

                    if (f[flag][j] > res)
                        res = f[flag][j];
                }
            }
            flag = 1-flag;
        }
            
        return res;
    }
};