#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    /*
     * @param A: an array
     * @return: total of reverse pairs
     */
    long long reversePairs(vector<int> &A) {
    	vector<int> B(A);
    	
    	return merge_sort(0,A.size()-1,A,B);
    }

    long long merge_sort(int l,int r,vector<int> &A,vector<int> &B)
    {
    	if (l>=r)
    		return 0;
    	int mid = l + ((r-l)>>1);

        long long sum = 0;
    	sum += merge_sort(l,mid,B,A);
    	sum += merge_sort(mid+1,r,B,A);

    	int p = l, q = mid+1, idx = l;
    	while (p <= mid && q <= r)
    	{
            if (A[p] < A[q])
            {
                B[idx++] = A[p++];
                // printf("idx:%d p:%d\n", idx,p);
                // sum += (long long)(p - idx);
            }
            else
            {
                B[idx++] = A[q++];
                sum += (long long)(q - idx);
            }
    	}
        while (p <= mid)
        {
            B[idx++] = A[p++];
            // sum += p - idx;
        }
        while (q <= r)
        {
            B[idx++] = A[q++];
            sum += q - idx;
        }
        return sum;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int d[] = {2, 4, 1, 3, 5};
    vector<int> v(d,d+5);
    cout << s.reversePairs(v) << endl;
    return 0;
}