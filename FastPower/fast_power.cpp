class Solution {
public:
    /*
     * @param a: A 32bit integer
     * @param b: A 32bit integer
     * @param n: A 32bit integer
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        long long ans = 1, p = a;
        while (n>0) {
        	if (n&1)
        		ans = ans * p % b;
        	p = p * p % b;
        	n >>= 1;
        }
        ans %= b;
        return ans;
    }
};