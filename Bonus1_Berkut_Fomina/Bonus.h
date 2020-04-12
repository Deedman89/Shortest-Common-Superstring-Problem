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
#include <set>

using namespace std;

// Функция, удаляющая одинаовые строки
vector<string> DeleteSameStrings(set<string>&); // K

class Graph { // A
public:
    Graph(const vector<string>&); // Конструктор, создающий полный граф по данному набору строк
    int GetSize() const; // Получение размера графа
    vector<vector<int>> GetMatrix() const; // Получение графа
    int GetValue(int i, int j); // Получение значения ячейки [i][j]
    void Print(); // Печать графа
private:
    vector<vector<int>> matrix;
    int size; // число вершин графа
};

// Функция, считающая длину максимальной одинаковой подстроки данных на вход строк
int OverLap(const string&, const string&);  //K

/*
* Функция, вычисляющая полное назначение максимального
* веса жажным методом. Время - O(k*k*log(k))
*/
vector<int> Assignment(const Graph&); //A

//Функция для вычисления покрытия циклами минимальной полной длины
vector<vector<int>> FullCoverage(const vector<int>&); //K

// Функция для обрезания первой строки на ее overlap со второй
string Prefix(const string&, int); //K

/* 
* Функция, сдвигающая цикл так,
* чтобы минимизировать overlap первой и последней строчек
*/
vector<int> Minimize(vector<int>, Graph&); //А+К

// Функция для сборки надстроки по одному циклу
string Cycle(vector<int>, Graph, vector<string>); // A

// Функция для сборки всего
/* 
* Тут надо сдвинуть все циклы, сделать для каждого надстроку 
* и собрать все в 1 надстроку
*/
string Builder(const vector<vector<int>>&, Graph&, const vector<string>&); //К
