class Solution {
public:
    /*
     * @param : as indicated in the description
     * @param : as indicated in the description
     * @return: Return the number of edges on the longest path with same value.
     */
    int LongestPathWithSameValue(vector<int> &A, vector<int> &E) {
    	int n = A.size();
    	if (n==0)
    		return 0;
    	vector<int> g[n];
    	for (int i = 0; i < E.size(); i+=2)
    	{
    		int a = E[i]-1, b = E[i+1]-1;
    		g[a].push_back(b);
    		g[b].push_back(a);
    	}

    	int f1[n],f2[n];
    	memset(f1,-1,sizeof(f1));
    	memset(f2,-1,sizeof(f2));
    	dfs(0,-1,f1,f2,A,g);

    	int ans = 0;
    	for (int i = 0; i < n; ++i)
    	{
    		ans = f1[i] > ans ? f1[i]:ans;
    		ans = f2[i] > ans ? f2[i]:ans;
    	}
    	return ans;
    }

    void dfs(int cur,int pre,int *f1,int *f2,vector<int> &A,vector<int> *g)
    {
    	if (f1[cur] >= 0)
    		return;

    	f1[cur] = f2[cur] = 0;
    	int m1 = -1, m2 = -1;
    	for (int i = 0; i < g[cur].size(); ++i)
    		if (g[cur][i] != pre)
    		{
    			int x = g[cur][i];
    			dfs(x,cur,f1,f2,A,g);
    			
    			if (A[cur] != A[x])
    				continue;

    			if (f1[x] > m1)
    			{
    				m2 = m1;
    				m1 = f1[x];
    			}
    			else
    			if (f1[x] > m2)
    				m2 = f1[x];
    		}

    	f1[cur] = m1 + 1;
    	f2[cur] = m1 + m2 + 2;
    }
};
