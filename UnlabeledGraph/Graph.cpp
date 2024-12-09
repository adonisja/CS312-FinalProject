
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
void Graph::add_vertex()
{
  set<int> s;            
  // Creates a new empty set of neighbors
  edges.push_back(s); 
  /* adds that empty set to the edges map with an automatic index assigned (starting from 0) 
  as the key */
}


//Adds an edge connecting source to target
void Graph::add_edge(int source, int target){
    assert (contains(source) && contains(target)); // checks if both source and target indices are valid
    edges[source].insert(target);
    edges[target].insert(source);
    // Creates an edge linking the target vertex to the source and vice-versa
    nedges++; // increments edges count afterwards
}

//Returns number of vertices
int Graph::V( ) const { 
	return edges.size();
  /* returns the count of sets (number of neighbor sets) in the graph,
  effectively giving the count of vertices in the graph */
} 

//Returns number of edges
int Graph::E( ) const { 
	return nedges; // returns the number of edges
} 

//Returns the vertices adjacent to vertex v
set<int> Graph::neighbors(int v) const{
    assert (contains(v)); // checks if v is a valid index 
    return edges[v]; 
    // returns the set of keys associated with that index (the neighbors of that vertex)
}

//Checks if vertex v is in the graph
bool Graph::contains(int v) const{
  return v < V(); 
  /* checks if v is a valid index, does this by comparing if the integer index v is 
  less than the size of V since the indices are auto-generated v is equal or greater than
  the size of V, then it isn't in the map*/
}

ostream& operator<< (ostream &out, const Graph &tyrellgraph)
{
    out << "============================" << std::endl;
    out << "Graph Summary: " << tyrellgraph.V() << " vertices, " << tyrellgraph.E() << " edges." << std::endl;
    out << "============================" << std::endl;
    for (int i = 0; i < tyrellgraph.V(); ++i) //Traversing each vertex: O(V)
    {
      out << i << " --> ";
      for (int neighbor : tyrellgraph.neighbors(i)) 
        // Printing each neighbor of the vertex: O(E)
      {
        out << neighbor << " ";
      }
      out << std::endl;
    }
  return out;
};