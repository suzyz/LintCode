class Solution {
public:
    /*
     * @param n: An integer
     * @return: A boolean which equals to true if the first player will win
     */
    bool firstWillWin(int n) {
    	if (n == 0)
    		return false;
    	if (n < 3)
    		return true;

    	bool f[n+2];
    	f[1] = f[2] = true;
    	for (int i = 3; i <= n; ++i)
    		f[i] = (!f[i-1]) || (!f[i-2]);
    	return f[n];
    }
};
