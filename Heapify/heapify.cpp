class Solution {
public:
    /*
     * @param A: Given an integer array
     * @return: nothing
     */
    void heapify(vector<int> &A) {
    	int n = A.size();
    	if (n<2)
    		return;

    	for (int i = (n-2)/2; i >= 0; --i)
    		heap_adjust(i,n,A);
    }
    void heap_adjust(int cur,int n,vector<int> &A)
    {
    	int i = cur, l = 2*cur + 1, r = 2*cur + 2;
    	while (l<n)
    	{
    		int j = i;
    		if (A[i] > A[l])
    			j = l;
    		if (r<n && A[j] > A[r])
    			j = r;

    		if (j == i)
    			return;

    		int tmp = A[j]; A[j] = A[i]; A[i] = tmp;

    		i = j;
    		l = 2*i + 1;
    		r = l + 1;
    	}
    }
};
