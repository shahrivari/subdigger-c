#pragma once
#include <unordered_set>
#include "graph.h"

using namespace std;

unordered_set<Vertex> set_union(const unordered_set<Vertex>& set1, const unordered_set<Vertex>& set2);
unordered_set<Vertex> set_intersection(const unordered_set<Vertex>& set1, const unordered_set<Vertex>& set2);
unordered_set<Vertex> set_difference(const unordered_set<Vertex>& set1, const unordered_set<Vertex>& set2);
unordered_set<Vertex> omit_smallers(const unordered_set<Vertex>& set1, Vertex v);


