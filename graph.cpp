#include "graph.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>


Graph::Graph(void)
{
}


Graph::~Graph(void)
{
}

void Graph::add_vertex(Vertex v)
{
	if(adjacency.find(v)==adjacency.end())
	{
		Adjancency adj;
		adjacency[v]=adj;		
	}
	else
	{
		cout<<"The vertex is already here: "<<v<<endl;
		exit(0);
	}
}

void Graph::add_edge(Vertex src,Vertex dest)
{
	if(adjacency.find(src)==adjacency.end())
		add_vertex(src);
	if(adjacency.find(dest)==adjacency.end())
		add_vertex(dest);
	adjacency[src].outs.insert(dest);
	adjacency[dest].ins.insert(src);
	adjacency[src].all.insert(dest);
	adjacency[dest].all.insert(src);
}

const unordered_set<Vertex>* Graph::get_neighbors(Vertex v) const 
{
	if(adjacency.find(v)==adjacency.end())
	{
		cout<<"The vertex does not exist: "<<v<<endl;
		exit(0);
	}
	return &(adjacency.find(v)->second.all);
}

void Graph::build_from_file(string path)
{
	adjacency.clear();
	ifstream infile(path);
	string line;
	int count=0;
	while (std::getline(infile, line))
	{
		count++;
		std::istringstream iss(line);
		Vertex a, b;
		if (!(iss >> a >> b)) 
		{ // error
			cout<<"Invalid file format at line:"<<count<<endl;
			exit(0);
		}
		add_edge(a,b);
	}
	infile.close();
}

vector<Vertex> Graph::get_vertices() const 
{
	vector<Vertex> result;
	for(unordered_map<Vertex,Adjancency>::const_iterator pos=adjacency.begin();pos!=adjacency.end();pos++)
		result.push_back(pos->first);
	return result;
}

unordered_set<Vertex> Graph::get_all_neighbors(const vector<Vertex>& vertices) const
{
	unordered_set<Vertex> neighbors(vertices.size()*10); 
	for (vector<Vertex>::const_iterator v=vertices.begin();v!=vertices.end();v++) {
		neighbors.insert(*v);
		neighbors.insert(get_neighbors(*v)->begin(), get_neighbors(*v)->end());
    }
    return neighbors;
}