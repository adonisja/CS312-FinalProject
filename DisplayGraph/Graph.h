#ifndef GRAPH_H
#define GRAPH_H

#include <set>
#include <vector>
#include <string>
#include <iostream>

/* Questions Set 1
1. Adjacency list is being used because there are edges. 
The data structure is a vector of sets in which each set stores the neighbors of a vertex.
2. Answers below.
*/

class Graph {
public:

    // CONSTRUCTOR
    Graph()  {nedges = 0; }

    // MODIFICATION MEMBER FUNCTIONS
    //adds a vertex to the graph. The index is automatically assigned.
    void add_vertex();

    //adds an edge connecting source to target
    // O(log n) where n = vertices
    void add_edge(int source, int target); // Accesses edges vector at source/target. Indices and inserts sets to make undirected edge connection


    // CONSTANT MEMBER FUNCTIONS
    int V( ) const; 	//returns number of vertices
    int E( ) const;     //returns number of edges

    //returns the vertices adjacent to vertex v
    // O(1)
    std::set<int> neighbors(int v) const;  // Returns the set at index v from edges vector, containing all vertices connected to v

    //checks if the vertex v is in the graph
    // O(1)
    bool contains(int v) const;   // Uses size() method to verify if vertex v exists in graph's vertex set

    // OVERLOADED OUTPUT OPERATOR
    friend std::ostream& operator<< (std::ostream &out, const Graph &g);

private:
  int nedges;
  std::vector<std::set<int> > edges;
};

#endif