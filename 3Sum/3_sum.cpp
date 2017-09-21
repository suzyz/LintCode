#include <iostream>
#include <vector>
using namespace std;

// class Solution {
// public:
    /*
     * @param numbers: Give an array numbers of n integer
     * @return: Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &numbers) {
        vector<vector<int> > ans;

        int n = numbers.size();
        sort(numbers.begin(),numbers.end());

        for (int i=0;i<n-2;i++)
        {
            if (i>0 && numbers[i]==numbers[i-1])
                continue;

            int h=i+1, t=n-1, target = -numbers[i];

            while (h<t) {

                if (numbers[h] + numbers[t] < target) {
                    h++;
                    while (h<t && numbers[h]==numbers[h-1]) h++;
                }
                else
                if (numbers[h] + numbers[t] > target) {
                    t--;
                    while (h<t && numbers[t]==numbers[t+1]) t--;
                }
                else
                {
                    int x[3] = {numbers[i],numbers[h],numbers[t]};
                    vector<int> cur(x,x+sizeof(x)/sizeof(int));
                    ans.push_back(cur);
                    h++;
                    while (h<t && numbers[h]==numbers[h-1]) h++;
                    t--;
                    while (h<t && numbers[t]==numbers[t+1]) t--;
                }
            }
        }

        return ans;
    }
// };

int main()
{
    int d[] = {-1,0,2,1,-1,4};
    std::vector<int> v(d,d+sizeof(d)/sizeof(int));
    std::vector<std::vector<int> > ans = threeSum(v);

    for(int i=0;i<ans.size();i++)
        printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
    return 0;
}

