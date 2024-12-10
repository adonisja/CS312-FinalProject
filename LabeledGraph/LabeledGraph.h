#ifndef LABELED_GRAPH_H
#define LABELED_GRAPH_H

#include <set>
#include <map>
#include <vector>
#include <string>
#include <iostream>

class LabeledGraph {
public:

    LabeledGraph()  {nedges = 0; }

    //adds a vertex with a specifc label
    void add_vertex(std::string vlabel);

    //adds an edge from vertex with source label to vertex with target label
    void add_edge(std::string source, std::string target);

    int V( ) const { return vertices.size(); } // returns number of vertices
    int E( ) const { return nedges; }       // returns number of edges
    bool contains(std::string vlabel) const;     // is the vlabel in the graph?
    std::set<int> neighbors(int v) const;  // returns all neighbors of the vlabel
    std::string label(int v) const;     // returns the label of vertex v
    int index(std::string vlabel);           // matches and returns the index of the vertex for the label given

    
    friend std::ostream& operator<< (std::ostream &out, const LabeledGraph &g);

private:
  int nedges;
  std::vector<std::set<int> > vertices;
  std::vector<std::string> labels;
  std::map<std::string, int> indexedLabels;
};

#endif
