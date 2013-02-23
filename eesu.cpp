#include "eesu.h"
#include "util.h"
#include "freelist.h"

EdgeBasedEnumerator::EdgeBasedEnumerator(const Graph& g):graph(g){
	count=0;
	vector<Vertex> vertices=graph.get_vertices();
	for(vector<Vertex>::const_iterator pos=vertices.begin();pos!=vertices.end();pos++)
	{
		EnumState* state= Freelist::get_new_state();
		state->root=*pos;
		state->subgraph.push_back(*pos);
		state->extension=omit_smallers(*graph.get_neighbors(*pos),*pos);
		stack.push(state);
	}
}

EdgeBasedEnumerator::~EdgeBasedEnumerator(void){}

void EdgeBasedEnumerator::enumurate_subgraphs(size_t size){
	while(stack.size()>0)
	{
		EnumState * top=stack.top();
		stack.pop();
        if (top->subgraph.size() == size) 
		{
            count++;
			Freelist::delete_state(top);
			continue;
        }
        while (top->extension.size() > 0) 
		{
			Vertex w = *top->extension.begin();
			top->extension.erase(w);
            EnumState* new_state=Freelist::get_new_state();
			new_state->root=top->root;
			new_state->subgraph=top->subgraph;
			new_state->subgraph.push_back(w);

            if (new_state->subgraph.size() == size) {
                long found = count++;
                if (found % 100000==0)
					printf("SubGraphs found so far: %d /tstack size is: %d\n", found,Freelist::freelist.size());
				Freelist::delete_state(new_state);				
            } else {
				unordered_set<Vertex> sub_and_neighbors = graph.get_all_neighbors(top->subgraph);
				unordered_set<Vertex> dif_set=set_difference(*graph.get_neighbors(w), sub_and_neighbors);
                unordered_set<Vertex> new_set = omit_smallers(dif_set, top->root);
				unordered_set<Vertex> new_ext = set_union(new_set, top->extension);
                new_state->extension = new_ext;
                stack.push(new_state);
            }			
        }
		Freelist::delete_state(top);
	}
	
}