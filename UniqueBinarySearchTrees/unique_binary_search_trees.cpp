#include <iostream>
#include <cstring>

class Solution {
public:
    /*
     * @param n: An integer
     * @return: An integer
     */
	
    int numTrees(int n) {
    	int f[n+1];
    	f[0] = f[1] = 1;
    	for (int i = 2; i<=n ; ++i)
        {
            f[i] = 0;
            for (int j = 0; j < i; ++j)
                f[i] += f[j] * f[i-1-j];
        }
        return f[n];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    printf("%d\n", s.numTrees(10));
    return 0;
}