class Solution {
public:
    /*
     * @param n: the integer to be reversed
     * @return: the reversed integer
     */
    int reverseInteger(int n) {
    	long long res = 0;
    	long long tmp = abs((long long)n);
    	while (tmp!=0)
    	{
    		res = 10*res + tmp%10;
    		tmp /= 10;
    	}

    	if (n < 0)
    		res *= -1;

    	if (res > INT_MAX || res < INT_MIN)
    		return 0;
    	else
    		return res;
    }
};
