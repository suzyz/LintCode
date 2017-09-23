class Solution {
public:
    /*
     * @param A: A list of integers
     * @param elem: An integer
     * @return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        int n = A.size();
        if (n==0)
            return 0;
            
        for (vector<int>::iterator it = A.begin(); it!=A.end(); ) {
            if (*it == elem) {
                it = A.erase(it);
                n--;
            }
            else
                ++it;
        }
        return n;
    }
};
