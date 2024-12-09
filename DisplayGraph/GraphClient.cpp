#include <iostream>
#include "Graph.h"
using namespace std;

int main()
{
    Graph robletograph;

    for (int i = 0; i < 6; i++)
    {
        robletograph.add_vertex();
    }

    robletograph.add_edge(2, 0); // Training Day - Eva Mendes
    robletograph.add_edge(2, 5); // Training Day - Ethan Hawke
    robletograph.add_edge(4, 2); // Denzel Washington - Training Day
    robletograph.add_edge(4, 3); // Denzel Washington - The Magnificent Seven
    robletograph.add_edge(4, 5); // Denzel Washington - Ethan Hawke
    robletograph.add_edge(5, 3); // Ethan Hawke - The Magnificent Seven
    robletograph.add_edge(3, 1); // The Magnificent Seven - Chris Pratt

    cout << robletograph;

    return 0;
}

/*
Q: If you run your program, you will notice that nothing is outputted; the graph is not
displayed. Can you figure out why?

A: Because the overloaded output operator is empty in Graph.cxx
*/