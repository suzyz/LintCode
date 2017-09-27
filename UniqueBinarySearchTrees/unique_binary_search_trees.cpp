class Solution {
public:
    /*
     * @param n: An integer
     * @return: An integer
     */

	int calc(int *f,int cur) {
		if (f[cur] > 0)
    		return f[cur];
    	f[cur] = 0;
    	for (int i=0;i<=cur-1;i++)
    		f[cur] += calc(f,i) * calc(f,cur-1-i);
    	return f[cur];
	}
	
    int numTrees(int n) {
    	int f[n+1];
    	memset(f,-1,sizeof(f));
    	f[0] = f[1] = 1;
    	return calc(f,n);
    }
};