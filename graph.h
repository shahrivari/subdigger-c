#pragma once
#include<map>
#include<vector>
#include<string>
#include<unordered_set>
#include<unordered_map>

using namespace std;

typedef int Vertex;

struct Adjancency{
	unordered_set<Vertex> ins;
	unordered_set<Vertex> outs;
	unordered_set<Vertex> all;
};

class Graph
{
	friend class SubGraphEnumurator;	
	unordered_map<Vertex,Adjancency> adjacency;	
	
public:
	Graph(void);
	~Graph(void);

	const unordered_set<Vertex>* get_neighbors(Vertex v) const ;
	unordered_set<Vertex> get_all_neighbors(const vector<Vertex>& vertices) const;
	void build_from_file(string path);
	vector<Vertex> get_vertices() const ;

private:
	void add_vertex(Vertex v);
	void add_edge(Vertex src,Vertex dest);


};
