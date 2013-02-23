#include <iostream>
#include <cstdlib>
#include "graph.h"
#include "eesu.h"

using namespace std;

int main()
{
	Graph g;
	g.build_from_file("C:\\Users\\Saeed\\Downloads\\Motif\\yeast");
	int x;
	cin>>x;

	EdgeBasedEnumerator enumu(g);
	enumu.enumurate_subgraphs(6);
	cout<<enumu.count<<endl;
	
	cin>>x;
}