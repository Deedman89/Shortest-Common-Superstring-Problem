/* 
   Буквой A отмечены объекты, за реализацию которых отвечает Фомина Анна
   Буквой K отмечены объекты, за реализацию которых отвечает Беркут Кирилл
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstdint>
#include <string>
using namespace std;

class Graph { // A
public:
    Graph(const vector<string>&); // Конструктор, создающий полный граф по данному набору строк
    void AddEdge(int, int, int);
    vector<int> GetEdgesFrom(int) const;
private:
    vector<vector<int>> matrix;
};

int OverLap(string, string); //K

vector<int> Assignment(); //A

vector<Graph> FullCoverage(vector<int>); //K

string Prefix(string, int); //A

string Minimize(Graph); //K

string Builder(vector<string>); //A
