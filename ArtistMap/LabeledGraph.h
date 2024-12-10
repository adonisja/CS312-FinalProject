#ifndef LABELED_GRAPH_H
#define LABELED_GRAPH_H

#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>

class LabeledGraph {
private:
    std::vector<std::set<int>> vertices;   // Adjacency list representation
    std::vector<std::string> labels;      // Maps index to label
    std::map<std::string, int> indexedLabels; // Maps label to index

    void create_artistMap(const std::string& fileName, char delimiter);

public:
    LabeledGraph(); // Default constructor
    LabeledGraph(const std::string& fileName); // Constructor with file input

    void add_vertex(const std::string& vlabel);
    void add_edge(const std::string& vlabel1, const std::string& vlabel2);

    size_t V() const; // Number of vertices
    size_t E() const; // Number of edges
    int index(const std::string& vlabel) const;
    std::string label(int index) const;
    const std::set<int>& neighbors(int index) const;
    void print_graph() const;

    std::map<int, int>BFS(int v); // this will map each index's distance from the source
    std::vector<int> pathTo(std::map<int, int>& parent_map, int target);
    /* This will store the parent map for each vertex */
    friend std::ostream& operator<<(std::ostream& out, const LabeledGraph& g);

};

#endif