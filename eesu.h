#pragma once
#include "graph.h"
#include <vector>
#include <unordered_set>
#include <stack>

using namespace std;

struct EnumState
{
	vector<Vertex> subgraph;
	unordered_set<Vertex> extension;
	Vertex root;
};

class EdgeBasedEnumerator
{
private:
	const Graph& graph;
	stack<EnumState *> stack;
public:
	long count;
	EdgeBasedEnumerator(const Graph& g);
	~EdgeBasedEnumerator(void);
	void enumurate_subgraphs(size_t k);

};
