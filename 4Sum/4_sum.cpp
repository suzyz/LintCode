class Solution {
public:
    /*
     * @param numbers: Give an array
     * @param target: An integer
     * @return: Find all unique quadruplets in the array which gives the sum of zero
     */
    vector<vector<int>> fourSum(vector<int> numbers, int target) {
       	int n = numbers.size();
       	int quadruplet[4];
       	vector<vector<int> > ans;
       	if (n<4)
       		return ans;

       	sort(numbers.begin(),numbers.end());

       	int i = 0;
       	while (i < n-3) {
       		quadruplet[0] = numbers[i];
       		int j = i+1;
       		while (j < n-2) {
       			quadruplet[1] = numbers[j];
       			int h = j+1, t = n-1, sum = target - numbers[i] - numbers[j];
       			while (h<t) {
       				int tmp = numbers[h] + numbers[t];
       				if (tmp == sum) {
    					quadruplet[2] = numbers[h];
    					quadruplet[3] = numbers[t];
       					ans.push_back(vector<int> (quadruplet,quadruplet+sizeof(quadruplet)/sizeof(int)));
       					h++;
       					t--;
       					while (h<t && numbers[h] == numbers[h-1]) h++;
       					while (h<t && numbers[t] == numbers[t+1]) t--;
       				}
       				else
       					if (tmp<sum) {
       						h++;
       						while (h<t && numbers[h] == numbers[h-1]) h++;
       					}
       					else {
       						t--;
       						while (h<t && numbers[t] == numbers[t+1]) t--;
       					}
       			}
       			j++;
       			while (j<n-2 && numbers[j]==numbers[j-1])
       				j++;
       		}
       		i++;
       		while (i<n-3 && numbers[i]==numbers[i-1])
       			i++;
       	}
       	return ans;
    }
};