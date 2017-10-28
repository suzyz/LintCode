
#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
using namespace std;

class ConnectingGraph {
public:
    vector<int> fa;
    /*
    * @param n: An integer
    */
    ConnectingGraph(int n) {
        int f[n+2];
        memset(f,-1,sizeof(f));
        fa = vector<int> (f,f+n+1);
    }

    /*
     * @param a: An integer
     * @param b: An integer
     * @return: nothing
     */
    void connect(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y)
            return;
        
        if (fa[x] < fa[y])
        {
            fa[x] += fa[y];
            fa[y] = x;
        }
        else
        {
            fa[y] += fa[x];
            fa[x] = y;
        }
    }

    /*
     * @param a: An integer
     * @param b: An integer
     * @return: A boolean
     */
    bool query(int a, int b) {
        return (find(a) == find(b));
    }

    int find(int a)
    {
        while (fa[a] > 0)
            a = fa[a];

        return a;
    }
};

int main()
{
    ConnectingGraph s(5);
    printf("%lu %d\n",(unsigned int)(-1),INT_MAX);
    cout << s.query(1,2) << endl;
    s.connect(1,2);
    s.connect(2,4);

    cout << s.query(1,4) << endl;

    s.connect(2,2);

    cout << s.query(1,2) << endl;

    return 0;
}
