/* 
   Буквой A отмечены объекты, за реализацию которых отвечает Фомина Анна
   Буквой K отмечены объекты, за реализацию которых отвечает Беркут Кирилл
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstdint>
#include <string>
#include <algorithm>
using namespace std;

class Graph { // A
public:
    Graph(const vector<string>&); // Конструктор, создающий полный граф по данному набору строк
    void AddEdge(int, int, int); // Добавление ребра из вершины from в вершину to с весом length
    vector<int> GetEdgesFrom(int) const; // Получение списка ребер, исходящих из вершины v
    int GetSize() const; // Получение размера графа
    vector<vector<int>> GetMatrix() const; // Получение графа
private:
    vector<vector<int>> matrix;
    int size; // число вершин графа
};

// Функция, считающая длину максимальной одинаковой подстроки данных на вход строк
int OverLap(const string&, const string&); //K

/*
* Функция, вычисляющая полное назначение максимального
* веса жажным методом. Время - O(k*k*log(k))
*/
vector<int> Assignment(const Graph& g); //A

//Функция для вычисления покрытия циклами минимальной полной длины
vector<vector<int>> FullCoverage(vector<int>); //K

string Prefix(string, int); //A

string Minimize(Graph); //K

string Builder(vector<string>); //A
