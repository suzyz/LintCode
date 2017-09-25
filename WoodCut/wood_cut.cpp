class Solution {
public:
    /*
     * @param L: Given n pieces of wood with length L[i]
     * @param k: An integer
     * @return: The maximum length of the small pieces
     */

	bool check(vector<int> &L,int len,int k) {
		int count = 0;
		for (int i=0;i<L.size();i++)
			count += L[i]/len;
		return count>=k;
	}

    int woodCut(vector<int> &L, int k) {
        long long sum = 0;

        for (int i=0;i<L.size();i++)
        	sum += L[i];

        if (sum<k)
        	return 0;

        int l = 0, r = sum/k;

        while (l<r) {
        	int mid = l + ((r - l)>>1) + 1;

        	if (check(L,mid,k))
        		l = mid;
        	else
        		r = mid-1;
        }
        return l;
    }
};
