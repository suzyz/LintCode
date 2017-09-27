#include <iostream>
#include <climits>
using namespace std;

class Solution1 {
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

class Solution2 {
public:
    /*
     * @param a: An integer
     * @param b: An integer
     * @return: An integer
     */
    int bitSwapRequired(int a, int b) {
        a ^= b;
        int ans = 0;
        
        if (a<0) {
            ans++;
            a ^= INT_MIN;
        }

        while (a>0) {
            if (a&1)
                ans++;
            a>>=1;
        }
        return ans;
    }
};

class Solution3 {
public:
    /*
     * @param a: An integer
     * @param b: An integer
     * @return: An integer
     */
    int bitSwapRequired(int a, int b) {
        a ^= b;
        int ans = 0;
        
        while (a) {
            ans++;
            a &= (a-1);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution3 s;
    int ans = s.bitSwapRequired(1,-1);
    printf("ans:%d\n", ans);

    for(int i=0;i<32;i++)
        printf("i:%d %d %d\n", i,((1<<i)&(INT_MIN)),((1<<i)&(-1)));

    for (int i = -10;i<=10;i++)
        printf("i:%d i^(-1):%d\n", i,i^(-1));
    printf("%d\n", 1<<31);
    return 0;
}