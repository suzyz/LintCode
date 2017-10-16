#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;

  struct directedgraphnode {
     int label;
     vector<directedgraphnode *> neighbors;
     directedgraphnode(int x) : label(x) {};
 };

class Solution {
public:
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {

        int n = graph.size();
        int nums[n+1],indegree[n+1];
       	
       	memset(indegree,0,sizeof(indegree));

        for (int i = 0; i < n; ++i)
        {
        	nums[i] = graph[i]->neighbors.size();
        	for (int j = 0; j < nums[i]; ++j)
        		++indegree[graph[i]->neighbors[j]->label];
        }

        bool vis[n+1];
        memset(vis,0,sizeof(vis));
        vector<DirectedGraphNode*> res;
        int k = n;
        while (k)
        {
			for (int i = 0; i < n; ++i)
	       	{
	       		int x = graph[i]->label;
	       		if (!vis[x] && indegree[x]==0)
	       		{
	       			--k;
	       			vis[x] = true;
	       			res.push_back(graph[i]);
	       			for (int j = 0; j < nums[i]; ++j)
	       			{
	       				int y = graph[i]->neighbors[j]->label;
	       				if (!vis[y])
	       					--indegree[y];
	       			}
	       		}
			}
        }
        
       	return res;
    }
};

int main(int argc, char const *argv[])
{
	DirectedGraphNode *node0 = new DirectedGraphNode(0);
	DirectedGraphNode *node1 = new DirectedGraphNode(1);
	DirectedGraphNode *node2 = new DirectedGraphNode(2);
	DirectedGraphNode *node3 = new DirectedGraphNode(3);
	node0->neighbors.push_back(node1);
	node0->neighbors.push_back(node2);
	node1->neighbors.push_back(node3);

	DirectedGraphNode * g[] = {node0,node1,node2,node3};
	std::vector<DirectedGraphNode *> v(g,g+4);

	Solution s;
	std::vector<DirectedGraphNode *> res = s.topSort(v);

	printf("res:\n");
	for (int i = 0; i < res.size(); ++i)
	{
		printf("%d:%d\n", i,res[i]->label);
	}

	return 0;
}