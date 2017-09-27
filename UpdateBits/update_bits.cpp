class Solution {
public:
    /*
     * @param n: An integer
     * @param m: An integer
     * @param i: A bit position
     * @param j: A bit position
     * @return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        int mask = 0, res = n;
        for (int k = i; k <= j; ++k)
            mask |= (1<<k);

        res -= res & mask;
        res |= m<<i;
        return res;
    }
};