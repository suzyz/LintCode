class Solution {
public:
    /*
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
    	if (x<0)
    		return -1;

    	int l = 0, r = x;
    	while (l<r) {
    		long long mid = l + ((r-l)>>1) + 1;

    		if (mid*mid==x)
    			return mid;
    		if (mid*mid<x)
    			l = mid;
    		else
    			r = mid-1;
    	}
    	return l;
    }
};
