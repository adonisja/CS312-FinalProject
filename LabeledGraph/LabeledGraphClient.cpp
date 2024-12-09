#include <iostream>
#include "LabeledGraph.cpp"

using namespace std;

int main()
{
    LabeledGraph tyrellgraph;
    tyrellgraph.add_edge("Chris Pratt", "Guardians of the Galaxy");
    tyrellgraph.add_edge("Guardians of the Galaxy", "Zoe Saldana");
    tyrellgraph.add_edge("Guardians of the Galaxy", "Vin Diesel");
    tyrellgraph.add_edge("Zoe Saldana", "Avatar");
    tyrellgraph.add_edge("Vin Diesel", "The Fate of the Furious");
    tyrellgraph.add_edge("Avatar", "Sam Worthington");
    tyrellgraph.add_edge("Avatar", "Michelle Rodriguez");
    tyrellgraph.add_edge("The Fate of the Furious", "Michelle Rodriguez");
    cout << tyrellgraph;
}