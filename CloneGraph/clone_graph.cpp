/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */


class Solution {
public:
    /*
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
    	if (node == NULL)
    		return NULL;

    	map<int,UndirectedGraphNode*> ptr;
    	clone_graph(node,ptr);
    	return ptr[node->label];
    }
    void clone_graph(UndirectedGraphNode* node,map<int,UndirectedGraphNode*> &ptr)
    {
    	if (ptr.count(node->label) == 0)
    		ptr[node->label] = new UndirectedGraphNode(node->label);

    	UndirectedGraphNode * res = ptr[node->label];

    	for (int i = 0; i < node->neighbors.size(); ++i)
    	{
    		UndirectedGraphNode *p = node->neighbors[i];
    		if (ptr.count(p->label) == 0)
    			clone_graph(p,ptr);

    		res->neighbors.push_back(ptr[p->label]);
    	}
    }
};
