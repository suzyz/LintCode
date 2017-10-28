class Solution {
public:
    /*
     * @param A: an array
     * @return: total of reverse pairs
     */
    long long reversePairs(vector<int> &A) {
    	long long res = 0;
    	vector<int> B(A);
    	merge_sort(0,A.size()-1,A,B,res);
    	return res;
    }

    void merge_sort(int l,int r,vector<int> &A,vector<int> &B,long long &res)
    {
    	if (l>=r)
    		return;
    	int mid = l + ((r-l)>>1);

    	merge_sort(l,mid,B,A,res);
    	merge_sort(mid+1,r,B,A,res);

    	int p = l, q = mid+1;
    	while (p <= mid && q <= r)
    	{

    	}
    }
};
