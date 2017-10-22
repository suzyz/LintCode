class Solution {
public:
    /*
     * @param n: An integer
     * @return: the nth prime number as description.
     */

	bool cmp(int a,int b)
	{
		return a<b;
	}
    int nthUglyNumber(int n) {
    	priority_queue<int> q1;
    	priority_queue<int,vector<int>,greater<int>> q2;
    	q1.push(1);
    	q2.push(1);

    	const int p[3] = {2,3,5};
    	int idx = 0;

    	--n;
    	while(n)
    	{
    		int min = q2.top();
    		for (int i = 0; i < 3; ++i)
    		{
    			q1.push(min * p[i]);
    			q2.push(min * p[i]);
    			--n;
    			if (n==0)
    				break;
    		}
    	}
    	return q1.top();
    }
};
