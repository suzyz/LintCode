#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    /*
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthLargestElement(int n, vector<int> &nums) {
    	int k = n-1;
    	n = nums.size()-1;
    	if (k>n)
    		return 0;
    	printf("k:%d n:%d\n",k,n );
    	return partition(k,0,n,nums);
    }

    int partition(int k,int st,int en,vector<int> &nums)
    {
    	printf("st:%d en:%d %d\n", st,en,nums[en]);
    	if (st>=en)
    		return nums[st];

    	int cur = nums[en], idx = st;
    	for (int i = st; i < en; ++i)
    		if (nums[i] > cur)
    		{
    			int tmp = nums[i]; nums[i] = nums[idx]; nums[idx] = tmp;
    			++idx;
    		}

    	nums[en] = nums[idx]; nums[idx] = cur;
    	printf("idx:%d\n", idx);
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		printf("%d ", nums[i]);
    	}
    	printf("\n");

    	if (idx == k)
    		return cur;
    	if (idx > k)
    		return partition(k,st,idx-1,nums);
    	else
    		return partition(k,idx+1,en,nums);
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	int d[] = {9,3,2,4,8};
	vector<int> v(d,d+5);
	cout<< "res:" << s.kthLargestElement(1,v) << endl;
	return 0;
}