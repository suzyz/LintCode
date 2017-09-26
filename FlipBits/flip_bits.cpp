#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    /*
     * @param a: An integer
     * @param b: An integer
     * @return: An integer
     */
    int bitSwapRequired(int a, int b) {
        a ^= b;
        int ans = 0;
        for (int i = 0; i<32; i++) {
            if ((a & (1<<i))!=0)
                ans++;
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    int ans = s.bitSwapRequired(1,-1);
    printf("ans:%d\n", ans);

    for(int i=0;i<32;i++)
        printf("i:%d %d %d\n", i,((1<<i)&(-3)),((1<<i)&(-1)));
    return 0;
}