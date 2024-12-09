#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
    Graph tyrellgraph;
    for (int i = 0; i < 5; i++) {tyrellgraph.add_vertex();}
    tyrellgraph.add_edge(0, 2);
    tyrellgraph.add_edge(0, 4);
    tyrellgraph.add_edge(1, 4);
    tyrellgraph.add_edge(2, 3);
    tyrellgraph.add_edge(2, 4);
    cout << tyrellgraph;
}

