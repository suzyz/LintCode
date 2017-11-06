class Solution {
public:
    /*
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
    	int n = prices.size(), res = 0;
        if (n<2)
            return 0;

        int low, high, best[n+2];
        low = prices[0];
        best[0] = 0;
    	for (int i = 1; i < n; ++i)
    	{
            low = min(low,prices[i]);
            best[i] = max(best[i-1],prices[i] - low);
        }
        res = max(res,best[n-1]);

        high = prices[n-1];
        for (int i = n-2; i > 0 ; --i)
        {   
            res = max(res,best[i-1] + high - prices[i]);
            high = max(high,prices[i]);
        }

    	return res;
    }
};
