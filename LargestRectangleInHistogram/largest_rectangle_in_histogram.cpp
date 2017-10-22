class Solution {
public:
    /*
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
    	int n = height.size();
    	int f[n+2], ans = 0;
    	memset(f,0,sizeof(f));

    	for (int i = 0; i < n; ++i)
    	{
    		f[i] = height[i];
    		ans = max(ans,f[i]);
    		for (int j = i-1; j >= 0; --j)
    		{
    			f[j] = min(f[j],height[i]);

    			if (f[j] == 0)
    				break;
    			ans = max(ans, f[j]*(i-j+1));
    		}
    	}
    	return ans;
    }
};
