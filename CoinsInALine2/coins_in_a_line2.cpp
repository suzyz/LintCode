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

        int sum[n];
        sum[0] = values[0];
        for (int i = 1; i < n; ++i)
            sum[i] = sum[i-1] + values[i];
    	
    	int f[n];
        f[0] = values[0];
        f[1] = values[1] > 0 ? values[0] + values[1] : values[0];
        for (int i = 2; i < n; ++i)
            f[i] = sum[i] - min(f[i-1],f[i-2]);
    	
    	return f[n-1] > sum[n-1] - f[n-1];
    }
};
