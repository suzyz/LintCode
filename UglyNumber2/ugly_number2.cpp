class Solution {
public:
    /*
     * @param n: An integer
     * @return: the nth prime number as description.
     */

    int nthUglyNumber(int n) {
        if (n==0)
            return 0;

    	const int primes[3] = {2,3,5};
        int idx[3],tmp[3];

        vector<int> nums(1,1);

        idx[0] = idx[1] = idx[2] = 0;

        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < 3; ++j)
                tmp[j] = primes[j] * nums[idx[j]];
        
            int m = min(tmp[0],min(tmp[1],tmp[2]));

            nums.push_back(m);

            for (int j = 0; j < 3; ++j)
                if (tmp[j] == m)
                    ++idx[j];
        }

        return nums[n-1];
    }
};
