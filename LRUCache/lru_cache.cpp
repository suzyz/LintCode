#include <list>
#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
using namespace std;

class LRUCache {
public:
    int cap, used;
    list<pair<int,int> > l;
    unordered_map<int,list<pair<int,int> >::iterator> position;

    /*
    * @param capacity: An integer
    */
    LRUCache(int capacity) {
        cap = capacity;
        used = 0;
    }

    /*
     * @param key: An integer
     * @return: An integer
     */
    int get(int key) {
        if(position.count(key) == 0)
            return -1;
        else
        {
            list<pair<int,int> >::iterator it = position[key];
            int res = (*it).second;
            if (it != l.begin())
            {
                l.insert(l.begin(),make_pair(key,res));
                l.erase(it);
                position[key] = l.begin();
            }

            return res;
        }
    }

    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void set(int key, int value) {
        if (cap <= 0)
            return;

        if (position.count(key) == 0)
        {
            if (used >= cap)
            {
                list<pair<int,int> >::iterator it = l.end();
                --it;
                position.erase((*it).first);
                l.erase(it);
            }
            else
                ++used;
        }
        else
        {
            list<pair<int,int> >::iterator it = position[key];
            l.erase(it);
        }

        l.insert(l.begin(),make_pair(key,value));
        position[key] = l.begin();
    }
};

void print_list(list<pair<int,int> > &l)
{
    for (list<pair<int,int> >::iterator i = l.begin(); i!= l.end(); ++i)
    {
        printf("%d ", (*i).first);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    LRUCache s(3);
    s.set(1,1);
    s.set(2,2);
    s.set(3,3);
    s.set(4,4);
    print_list(s.l);
    printf("%d\n", s.get(4));
    printf("%d\n", s.get(3));
    printf("%d\n", s.get(2));
    printf("%d\n", s.get(1));
    print_list(s.l);
    s.set(5,5);
    print_list(s.l);
    printf("%d\n", s.get(1));
    printf("%d\n", s.get(2));
    print_list(s.l);
    return 0;
}