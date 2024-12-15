#include "LabeledGraph.h"
#include <iostream>
#include <string>

void displayPath(const LabeledGraph& g, const std::vector<int>& path) {
    if (path.empty()) {
        std::cout << "There's no path between these vertices." << std::endl;
        return;
    }

    std::cout << g.label(path[0]);
    for (size_t i = 1; i < path.size(); i++) {
        std::cout << " --> " << g.label(path[i]);
    }
    std::cout << std::endl;
}

int main() {

    LabeledGraph g("artists_pairs.txt");

    std::string sourceVertex;
    std::cout << "Enter your source vertex: ";
    std::getline(std::cin, sourceVertex);

    int sourceIndex = g.index(sourceVertex);
    if (sourceIndex == -1) {
        std::cout << "Error: Source vertex doesn't exist in graph." << std::endl;
        return 1;
    }

    std::map<int, int> parentMap = g.BFS(sourceIndex);
    std::cout << "Shortest paths from " << sourceVertex 
              << " to other vertices are created." << std::endl;

    while (true) {
        std::string targetVertex;
        std::cout << "Enter a target vertex to display the shortest path from "
                  << sourceVertex << " to that vertex. Type -1 to exit: ";
        std::getline(std::cin, targetVertex);

        if (targetVertex == "-1") {
            break;
        }

        int targetIndex = g.index(targetVertex);
        if (targetIndex == -1) {
            std::cout << "Error: Target vertex doesn't exist in graph.." << std::endl;
            continue;
        }

        std::vector<int> path = g.pathTo(parentMap, targetIndex);

        std::cout << "Shortest Path from " << sourceVertex 
                  << " to " << targetVertex << ":" << std::endl;
        displayPath(g, path);
    }

    std::cout << "Bye!" << std::endl;
    return 0;
}