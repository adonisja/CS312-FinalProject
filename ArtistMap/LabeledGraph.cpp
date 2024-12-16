#include "LabeledGraph.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <queue>
#include <algorithm>

LabeledGraph::LabeledGraph() {
    // Default constructor: initializes an empty graph
}

LabeledGraph::LabeledGraph(const std::string& fileName) {
    char delimiter = ','; // Assumes a comma-separated file for singers also enables easy replacement
    create_artistMap(fileName, delimiter);
}

void LabeledGraph::create_artistMap(const std::string& fileName, char delimiter) {
    std::ifstream file(fileName);

    if (!file) {
        std::cerr << "Unable to open file: " << fileName << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string singer1, singer2;

        // Extract the two singers separated by the delimiter
        if (std::getline(ss, singer1, delimiter) && std::getline(ss, singer2)) {
            // Ensure both vertices are added before adding the edge
            add_vertex(singer1);
            add_vertex(singer2);
            add_edge(singer1, singer2);
        } else {
            std::cerr << "Invalid line: " << line << std::endl;
        }
    }

    file.close();
}


void LabeledGraph::add_vertex(const std::string& vlabel) {
    if (indexedLabels.find(vlabel) == indexedLabels.end()) {
        indexedLabels[vlabel] = V();       // Assign next available index
        labels.push_back(vlabel);         // Add the label
        vertices.push_back(std::set<int>());  // Add an empty set for neighbors
    }
}

void LabeledGraph::add_edge(const std::string& vlabel1, const std::string& vlabel2) {
    auto it1 = indexedLabels.find(vlabel1);
    auto it2 = indexedLabels.find(vlabel2);

    if (it1 != indexedLabels.end() && it2 != indexedLabels.end()) {
        int index1 = it1->second;
        int index2 = it2->second;

        // Add the edge in both directions (undirected graph)
        vertices[index1].insert(index2);
        vertices[index2].insert(index1);
    } else {
        std::cerr << "Error: One or both vertices not found: " << vlabel1 << ", " << vlabel2 << std::endl;
    }
}


size_t LabeledGraph::V() const {
    return vertices.size();
}

size_t LabeledGraph::E() const {
    size_t edges = 0;
    for (const auto& neighbors : vertices) {
        edges += neighbors.size();
    }
    return edges / 2; // Since each edge is counted twice in an undirected graph
}

int LabeledGraph::index(const std::string& vlabel) const {
    auto it = indexedLabels.find(vlabel);
    if (it != indexedLabels.end()) {
        return it->second;
    }
    return -1; // Return -1 if the vertex does not exist
}

std::string LabeledGraph::label(int index) const {
    if (index >= 0 && index < labels.size()) {
        return labels[index];
    }
    return ""; // Return empty string if index is out of bounds
}

const std::set<int>& LabeledGraph::neighbors(int index) const {
    if (index >= 0 && index < vertices.size()) {
        return vertices[index];
    }
    static const std::set<int> empty;
    return empty; // Return empty set if index is out of bounds
}

void LabeledGraph::print_graph() const {
    for (size_t i = 0; i < vertices.size(); ++i) {
        std::cout << labels[i] << ": ";
        for (int neighbor : vertices[i]) {
            std::cout << labels[neighbor] << " ";
        }
        std::cout << std::endl;
    }
}

std::map<int, int> LabeledGraph::BFS(int v) {
    std::map<int, int> parent_map; // Tracks the parent of each vertex
    std::queue<int> q;
    std::vector<bool> visited(V(), false); // Tracks visited vertices

    // Initialize BFS
    q.push(v);
    visited[v] = true;
    parent_map[v] = -1; // Root has no parent

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : neighbors(current)) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent_map[neighbor] = current; // Set the parent
                q.push(neighbor);
            }
        }
    }

    return parent_map;
}

std::vector<int> LabeledGraph::pathTo(std::map<int, int>& parent_map, int target) {
    std::vector<int> path;

    // Trace back from the target to the source using the parent map
    for (int current = target; current != -1; current = parent_map[current]) {
        path.push_back(current);
    }

    // Reverse the path to make it from source to target
    std::reverse(path.begin(), path.end());

    return path;
}


std::ostream& operator<<(std::ostream& out, const LabeledGraph& g) {
    out << "======================================" << std::endl;
    out << "Graph Summary: " << g.V() << " vertices, " << g.E() << " edges." << std::endl;
    out << "======================================" << std::endl;
    for (size_t i = 0; i < g.V(); ++i) {
        out << g.label(i) << std::endl;
        for (int neighbor : g.neighbors(i)) {
            out << "\t" << g.label(neighbor) << std::endl;
        }
        out << std::endl;
    }
    return out;
}
