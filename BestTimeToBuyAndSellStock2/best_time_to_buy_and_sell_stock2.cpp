class Solution {
public:
    /*
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
    	int n = prices.size(), res = 0;
    	for (int i = 0; i < n-1; ++i)
    		if (prices[i] < prices[i+1])
    			res += prices[i+1] - prices[i];

    	return res;
    }
};
