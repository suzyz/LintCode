class Solution {
public:
    /*
     * @param n: A long integer
     * @return: An integer, denote the number of trailing zeros in n!
     */
    long long trailingZeros(long long n) {
    	long long count5 = 0 , fac = 5;
    	while (n>=fac) {
    		count5 += n/fac;
    		fac *= 5;
    	}
    	return count5;
    }
};