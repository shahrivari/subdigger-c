#include "util.h"

unordered_set<Vertex> set_union(const unordered_set<Vertex>& set1, const unordered_set<Vertex>& set2)
{	
	unordered_set<Vertex> result;
	result.insert(set1.begin(),set1.end());
	result.insert(set2.begin(),set2.end());
	return result;
}

unordered_set<Vertex> set_intersection(const unordered_set<Vertex>& set1, const unordered_set<Vertex>& set2)
{
	unordered_set<Vertex> result;
	if(set1.size()>set2.size())
	{
		for(unordered_set<Vertex>::const_iterator pos=set2.begin();pos!=set2.end();pos++)
			if(set1.find(*pos)!=set1.end())
				result.insert(*pos);
	}
	else
	{
    	for(unordered_set<Vertex>::const_iterator pos=set1.begin();pos!=set1.end();pos++)
			if(set2.find(*pos)!=set2.end())
				result.insert(*pos);
	}
	
	return result;
}

unordered_set<Vertex> set_difference(const unordered_set<Vertex>& set1, const unordered_set<Vertex>& set2)
{
	unordered_set<Vertex> result;
	for(unordered_set<Vertex>::const_iterator pos=set1.begin();pos!=set1.end();pos++)
		if(set2.find(*pos)==set2.end())
			result.insert(*pos);
	return result;
}

unordered_set<Vertex> omit_smallers(const unordered_set<Vertex>& set1, const Vertex v)
{
	unordered_set<Vertex> result;
	for(unordered_set<Vertex>::const_iterator pos=set1.begin();pos!=set1.end();pos++)
		if(*pos<v)
			result.insert(*pos);
	return result;
}