class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        if(s.length()!=t.length())
            return false;
            
        int count['z'-'A'+1];
        memset(count,0,sizeof(count));
        
        for(int i=0;i<s.length();i++)
            count[s[i]-'A']++;
    
        for(int i=0;i<t.length();i++)
            count[t[i]-'A']--;
            
        for(int i=0;i<='z'-'A';i++)
            if (count[i]!=0)
                return false;
        return true;
    }
};
