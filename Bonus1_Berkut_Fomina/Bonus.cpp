#include <iostream>
#include <vector>
#include <string>
#include "Bonus.h"

using namespace std;

// Функция, считающая длину максимальной одинаковой подстроки данных на вход строк
int Overlap(const string& s1, const string& s2)  
{
    int overlap = 0;
    int j = 0;
    int s1_size = s1.size() - 1;
    int s2_size = s2.size();
    for (int i = s1_size; i > -1; i--)  //Считаем максимальню длину суффикса s1 совпадающего с префиксом s2
    {
        j++;
        for (j; j < s2_size; j++)
        {
            string prefix = s1.substr(i);
            string sufix = s2.substr(0, j);
            if (prefix == sufix)
            {
                overlap = j;
                break;
            }
            else
                break;
        }
    }
    return overlap;
}


class Graph { 
public:
    // Конструктор, создающий полный граф по набору строк input
    Graph(const vector<string>& input){
        int n = input.size();
        size = n;
        matrix.resize(n); // Создаем пустую матрицу смежности размера n*n
        for (auto i : matrix) i.resize(n);
        for (int i = 0; i < n; i++) // Заполняем матрицу смежности
            for (int j = 0; j < n; j++) AddEdge(i, j, Overlap(input[i], input[j]));
    };

    // Добавление ребра из вершины from в вершину to с весом length
    void AddEdge(int from, int to, int length){
        matrix[from][to] = length;
    };

    // Получение списка ребер, исходящих из вершины v
    vector<int> GetEdgesFrom(int v) const{
        vector<int> res = matrix[v];
    };

private:
    vector<vector<int>> matrix;
    int size; // размер матрицы
};

