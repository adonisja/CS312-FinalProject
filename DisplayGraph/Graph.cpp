
#include <set>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "Graph.h"
#include <cassert>
#include "Graph.h"

using namespace std;

//Adds a vertex to the graph
//The index of the new vertex is automatically assigned
void Graph::add_vertex(){
  set<int> s;
  edges.push_back(s);
}


//Adds an edge connecting source to target
void Graph::add_edge(int source, int target){
    assert (contains(source) && contains(target));
    edges[source].insert(target);
    edges[target].insert(source);
    nedges++;
}

//Returns number of vertices
int Graph::V( ) const { 
	return edges.size(); 
} 

//Returns number of edges
int Graph::E( ) const { 
	return nedges; 
} 

//Returns the vertices adjacent to vertex v
set<int> Graph::neighbors(int v) const{
    assert (contains(v));
    return edges[v];
}

//Checks if vertex v is in the graph
bool Graph::contains(int v) const{
  return v < V();
}

// O(V + E) time, V = vectors E = edges
ostream &operator<<(ostream &out, const Graph &g)
{
  out << "======================================\n";
  out << "Graph Summary: " << g.V() << " vertices, " << g.E() << " edges\n";
  out << "======================================\n";

  // Iterate through vertices
  for (int v = 0; v < g.V(); v++)
  {
    // Only output vertices with neighbors
    if (!g.neighbors(v).empty())
    {
      out << v << " --> ";
      // Output neighbors
      for (int neighbor : g.neighbors(v))
      {
        out << neighbor << " ";
      }
      out << "\n";
    }
  }
  return out;
}

/*
Questions Set 2:

1. A variable for the # of vertices is not needed because edges.size() already returns the vertex count.

2. Big-O time = O(V + E) iterating through every vertex V and it's edges E in the output operator.

3. Big-O time with matrix representation = O(V^2) checking every cell in the adjacency matrix.
*/