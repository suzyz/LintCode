class Solution {
public:
    /*
     * @param : the prices
     * @param : the length of rod
     * @return: the max value
     */
    int cutting(vector<int>& prices, int n) {
       	int f[n+1];
       	f[0] = 0;
       	for (int i = 1; i <= n; ++i)
       	{
       		f[i] = 0;
       		for (int j = 1; j <= i; ++j)
       			f[i] = f[i-j] + prices[j-1] > f[i] ? f[i-j] + prices[j-1]:f[i];
       	}
       	return f[n];
    }
};
