class Solution {
public:
    /*
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
    	int n = values.size();
    	if (n == 0)
    		return false;
    	if (n == 1)
    		return (values[0] > 0);

    	reverse(values.begin(), values.end());
    	int sum1 = 0, sum2 = 0, f[n+2];
    	f[0] = 0;
    	f[1] = values[0];
    	for (int i = 2; i <= n; ++i)
    	{
    		f[i] = max(sum2 - f[i-1], sum1 - f[i-2] + values[i-2]) + values[i-1];
    	}
    	
    	return f[n] > 
    }
};
