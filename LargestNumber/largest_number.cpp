#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    /*
     * @param nums: A list of non negative integers
     * @return: A string
     */
    static bool my_cmp(const string &a,const string &b)
    {
        string c = a+b, d = b+a;
        return c>d;
    }

    string largestNumber(vector<int> &nums) {
        int n = nums.size();
        if (n==0)
            return "";

        vector<string> s;
        for (int i = 0; i < n; ++i)
        {
            int cur = nums[i];
            if (cur==0)
                s.push_back("0");
            else
            {
                string tmp;
                while (cur>0)
                {
                    tmp = (char)(cur%10 + '0') + tmp;
                    cur/=10;
                }
                s.push_back(tmp);
            }
        }

        sort(s.begin(),s.end(),my_cmp);

        string ans;
        for (int i = 0; i < n; ++i)
            ans +=s[i];

        while (ans.length()>1 && ans[0]=='0')
            ans.erase(ans.begin());
        
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int d[] = {41,23,87,55,50,53,18,9,39,63,35,33,54,25,26,49,74,61,32,81,97,99,38,96,22,95,35,57,80,80,16,22,17,13,89,11,75,98,57,81,69,8,10,85,13,49,66,94,80,25,13,85,55,12,87,50,28,96,80,43,10,24,88,52,16,92,61,28,26,78,28,28,16,1,56,31,47,85,27,30,85,2,30,51,84,50,3,14,97,9,91,90,63,90,92,89,76,76,67,55};
    std::vector<int> v(d,d+sizeof(d)/sizeof(int));

    Solution s;
    string ans = s.largestNumber(v);
    cout<<ans<<endl;
    return 0;
}