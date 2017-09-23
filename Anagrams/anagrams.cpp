class Solution {
public:
    /*
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        vector<string> ans;
        if (strs.size()==0)
            return ans;
        
        int count1[26],count2[26];
        
        for (vector<string>::iterator x = strs.begin(); x!=strs.end(); ++x)
        {
            memset(count1,0,sizeof(count1));
            for(int i=0;i<(*x).length();i++)
                count1[(*x)[i]-'a']++;

            bool flag=false;
            for(vector<string>::iterator y = x+1; y!=strs.end(); )
            {
                if ((*y).length() != (*x).length())
                {
                    y++;
                    continue;
                }
                memset(count2,0,sizeof(count2));
                for(int j=0;j<(*y).length();j++)
                    count2[(*y)[j]-'a']++;

                if (memcmp(count1,count2,sizeof(count1))==0)
                {
                    flag=true;
                    ans.push_back((*y));
                    y = strs.erase(y,y+1);
                }
                else
                    ++y;
            }
            if(flag)
                ans.push_back(*x);
        }
        return ans;
    }
};