#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_set>
using namespace std;

class Solution {
public:
    /*
     * @param start: a string
     * @param end: a string
     * @param dict: a set of string
     * @return: a list of lists of string
     */
    vector<string> q;
    vector<int> pre;
        
    vector<vector<string> > findLadders(string &start, string &end, unordered_set<string> &dict) {
        vector<vector<string> > res;

        if (start == end)
        {
            vector<string> tmp(2,"");
            tmp[0] = start;
            tmp[1] = end;
            res.push_back(tmp);
            return res;
        }

        dict.insert(end);

        unordered_set<string> vis;
        
        q.push_back(start);
        pre.push_back(-1);
        int head = 0, tail = 1;
        vis.insert(start);

        int n = start.length();
        int level = 1;

        bool found = false;

        while (head<tail && !found)
        {
            ++level;
            int num = tail - head;
            unordered_set<string> this_level;
            while (num--)
            {
                string cur = q[head++];
                
                for (int i = 0; i < n; ++i)
                {
                    string y = cur;
                    for (int j = 'a'; j <= 'z'; ++j)
                    if (j!=cur[i])
                    {
                         y[i] = j;
                        if (y == end)
                        {
                            found = true;
                            vector<string> tmp(level,"");
                            tmp[level-1] = end;
                            int idx = head-1;
                            for (int k = level-2; k >= 0 ; --k)
                            {
                                tmp[k] = q[idx];
                                idx = pre[idx];
                            }
                            res.push_back(tmp);
                        }
                        else
                        if (dict.count(y) && vis.count(y)==0)
                        {
                            this_level.insert(y);
                            q.push_back(y);
                            pre.push_back(head-1);
                            ++tail;
                        }
                    }
                }
            }
            if (!found)
            {
                for (unordered_set<string>::iterator i = this_level.begin(); i != this_level.end(); ++i)
                    vis.insert(*i);
            }
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string st = "cet";
    string en = "ism";
    
    // string k[] = {"hot","cog","dog","tot","hog","hop","pot","dot"};
    string k[] = {
"kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin","dun","pat","ten","mob"};
    
    unordered_set<string> dict(k,k+598);

    std::vector<std::vector<string> > res = s.findLadders(st,en,dict);
    printf("res:%d\n", res.size());
    return 0;
}
