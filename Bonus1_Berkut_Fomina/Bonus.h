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
    void AddEdge(int, int, int); // Добавление ребра из вершины from в вершину to с весом length
    vector<int> GetEdgesFrom(int) const; // Получение списка ребер, исходящих из вершины v
private:
    vector<vector<int>> matrix;
};

int OverLap(const string&, const string&); //K
// Функция, считающая длину максимальной одинаковой подстроки данных на вход строк

vector<int> Assignment(); //A

vector<Graph> FullCoverage(vector<int>); //K

string Prefix(string, int); //A

string Minimize(Graph); //K

string Builder(vector<string>); //A
