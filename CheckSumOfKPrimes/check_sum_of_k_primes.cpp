class Solution {
public:
	const int maxtot = 1200;
	int tot = 0;
	int primes[maxtot];
    /*
     * @param : an int
     * @param : an int
     * @return: if N can be expressed in the form of sum of K primes, return true; otherwise, return false.
     */
    bool isSumOfKPrimes(int n, int k) {

    	init();

    	long long f[n+2][k+2];
    	memset(f,0,sizeof(f));

    }

    void init(int n)
    {
    	bool not_prime[n+2];
    	memset(not_prime,0,sizeof(not_prime));

    	not_prime[0] = not_prime[1] = true;
    	for (int i = 2; i <= n; ++i)
    	{
    		if (!not_prime[i])
    		{
    			primes[++tot] = i;
    			
    		}

    	}

    }
};
