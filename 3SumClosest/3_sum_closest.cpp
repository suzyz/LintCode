#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /*
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> &numbers, int target) {
    	int n = numbers.size();
    	if (n<3)
    		return 0;

    	sort(numbers.begin(),numbers.end());
    	int ans = numbers[0] + numbers[1] + numbers[2];

    	for (int i=0;i<n-2;i++) {
    		int h = i+1, t = n-1;

    		while (h<t) {
    			int sum = numbers[i] + numbers[h] + numbers[t];
    			if (abs(sum - target) < abs(ans - target))
    				ans = sum;

    			if (sum == target)
    				return target;
    			else
	    			if (sum > target)
	    				t--;
	    			else
	    				h++;
    		}
    	}
    	return ans;
    }
};

int main()
{
	int d[] = {-2,-3,5,-1,-4,5,-11,7,1,2,3,4,-7,-1,-2,-3,-4,-5};
	vector<int> v(d,d+sizeof(d)/sizeof(int));
	Solution s;
	printf("%d\n",s.threeSumClosest(v,45));
}
