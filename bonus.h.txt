#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstdint>

class Graph {
public:
    Graph(vector<string>);
    void AddEdge(int, int, int); //A
    GetEdgesFrom(int) const;
};

int OverLap(string, string); //K

vector<int> Assignment(); //A

vector<Graph> FullCoverage(vector<int>); //K

string Prefix(string, int); //A

string Minimize(Graph); //K

string Builder(vector<string>); //A







