#include <set>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "LabeledGraph.h"

using namespace std;

void LabeledGraph::add_vertex(string vlabel){  
  // vlabel is added as new variable to hold the strings that represent names
  labels.push_back(vlabel); //the vlabel is added to a list called labels
  indexedLabels.insert(pair<string, int>(vlabel, V()));
  /* indexLabels is now created as a map linking each label (string/name) to an index (or number)
  making it easier to look-up, remember this is mapped e.g {"Chris Pratt": 0} */
  set<int> s; 
  /* now we initialize a set with to store the neighbors for each index */
  
  vertices.push_back(s);
}

void LabeledGraph::add_edge(string source, string target){
    if (!contains(source))
      add_vertex(source);
    if (!contains(target))
      add_vertex(target);
    vertices[indexedLabels[source]].insert(indexedLabels[target]);
    vertices[indexedLabels[target]].insert(indexedLabels[source]);
    nedges++;
}

bool LabeledGraph::contains(string vlabel) const {
  return indexedLabels.find(vlabel) != indexedLabels.end();
}

set<int> LabeledGraph::neighbors(int v) const{
    return vertices[v];
}

string LabeledGraph::label(int v) const {
    return labels[v];
}

int LabeledGraph::index(string vlabel) {
    return indexedLabels[vlabel];
}

ostream& operator<< (ostream &out, const LabeledGraph &g) {
  out << "======================================" << endl;
  out << "Graph Summary: " << g.V() << " vertices, " << g.E() << " edges." << endl;
  out << "======================================" << endl;
  for (int i = 0; i < g.V(); i++)
  {
    out << g.label(i) << endl;
    for (int neighbor : g.neighbors(i)) 
        // Printing each neighbor of the vertex: O(E)
      {
        out << "\t";
        out << g.label(neighbor) << endl;
      }
      out << std::endl;
  }
  return out;
}

/* Q1: What new variables were added to LabeledGraph that were not in Graph
 and what do you think they are used for?
    - vlabel was added to store the string representation of names for the graph
    - labels was used as a container to store those vlabels in a list.
    - indexedLabels maps each vlabel to an integer to make it easier to access the data in
      the map.
    - here the container that stores the list of connections is called "vertices", however
      it is the same as "edges" in UnlabeledGraph.cpp
  
  Q2: What changes do you see in the add_vertex and add_edge functions
      (LabeledGraph vs Graph)? Explain why you think those changes were made.
    -
 
 
 
 */