#include <iostream>
#include "LabeledGraph.cpp"

using namespace std;

int main() {
    string fileName = "../artists_pairs.txt";
    LabeledGraph artistGraph(fileName);

    cout << "Total vertices: " << artistGraph.V() << endl;
    cout << "Total edges: " << artistGraph.E() << endl;

    string sourceArtist, targetArtist;
    cout << "Enter the source artist: ";
    getline(cin, sourceArtist);

    cout << "Enter the target artist or -1 to exit: ";
    getline(cin, targetArtist);

    int sourceIndex = artistGraph.index(sourceArtist);
    
    while (targetArtist != "-1")
    {
        int targetIndex = artistGraph.index(targetArtist);

        // Perform BFS to get the parent map
        map<int, int> parent_map = artistGraph.BFS(sourceIndex);

        // Get the shortest path from source to target
        vector<int> path = artistGraph.pathTo(parent_map, targetIndex);

        if (path.size() <= 1) {
            cout << "No path exists between " << sourceArtist << " and " << targetArtist << "." << endl;
        } else {
            cout << "Shortest path from " << sourceArtist << " to " << targetArtist << ":\n";
            for (int vertex : path) {
                cout << artistGraph.label(vertex);
                if (vertex != path.back())
                {
                    cout << " --> ";
                } else{
                    cout << endl;
                }
            }
            cout << endl;
        }
        cout << "Enter the next target artist or -1 to exit: ";
        getline(cin, targetArtist);
    }
    return 0;
}