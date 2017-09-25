class Solution {
public:
    /*
     * @param nums: An ineger array
     * @return: An integer
     */
    int removeDuplicates(vector<int> &nums) {
        int n = nums.size();
        if (n<2)
            return n;
        
        vector<int>::iterator pre = nums.begin();
        vector<int>::iterator cur = pre+1;

        while( cur!=nums.end() ) {
            if (*cur == *pre) {
                n--;
                cur = nums.erase(cur);
            }
            else {
                pre = cur;
                cur++;
            }
        }
        return n;
    }
};
