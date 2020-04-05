#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
};


class Graph
{ 
public:
    // Конструктор, создающий полный граф по набору строк input
    Graph(const vector<string>& input)
    {
        int n = input.size();
        size = n;
        matrix.resize(n); // Создаем пустую матрицу смежности размера n*n
        for (auto i : matrix) i.resize(n);
        for (int i = 0; i < n; i++) // Заполняем матрицу смежности
            for (int j = 0; j < n; j++) AddEdge(i, j, Overlap(input[i], input[j]));
    };
    // Добавление ребра из вершины from в вершину to с весом length
    void AddEdge(int from, int to, int length)
    {
        matrix[from][to] = length;
    };
    // Получение списка ребер, исходящих из вершины v
    vector<int> GetEdgesFrom(int v) const
    {
        vector<int> res = matrix[v];
    };
    // Получение размера графа
    int GetSize() const
    {
        return size;
    };
    // Получение графа
    vector<vector<int>> GetMatrix() const
    {
        return matrix;
    };
private:
    vector<vector<int>> matrix;
    int size; // размер матрицы
};

/*
* Функция, вычисляющая полное назначение максимального
* веса жажным методом. Время - O(k*k*log(k))
*/
vector<int> Assignment(const Graph& g)
{
    vector<vector<int>> a = g.GetMatrix(); // Копия нашей матрицы смежности
    vector<int> res; // Массив для записи результата
    /* res[i] = j означает выбранное ребро из i в j */
    int n = g.GetSize();
    res.resize(n);
    vector<vector<bool>> allow;
    allow.resize(n);
    for (auto i : allow) i.assign(n, true); // Заполнили матрицу достуных клеток
    while (true)
    {
        int max = -1, maxi = -1, maxj = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (allow[i][j])
                    continue;
                if (a[i][j] > max)
                {
                    max = a[i][j];
                    maxi = i; maxj = j;
                }
            }
        }
        if (max == -1) break;
        res[maxi] = maxj;
        for (int i = 0; i < n; i++)
        {
            allow[maxi][i] = true;
            allow[i][maxj] = true;
        }
    }
    return res;
};

//вычисление покрытия циклами минимальной полной длины, на выходе вектор векторов в которых записаны
//вершины циклов в порядке соединения их рёбрами
vector<vector<int>> FullCoverage(const vector<int>& a)
{
    vector<int> assign = a;
    int assign_size = assign.size();
    vector<vector<int>> cycles(assign_size); 
    vector<bool> mark(assign_size, false); //заводим вектор отметок посещения вершин
    int cycle = 0;
    for (int i = 0; i < assign_size; i++) //дальше мы бегаем по вектору из входа и составляем наши циклы,
    {                                     //отмечая уже посещённые вершины
        if (mark[i] == false)
        {
            cycles[cycle].push_back(i);
            mark[i] = true;
            int j = assign[i];
            while (true)
            {
                if (count(cycles[cycle].begin(), cycles[cycle].end(), j) == 0)
                {
                    cycles[cycle].push_back(j);
                    mark[j] = true;
                }
                if (assign[j] == i)
                    break;
                int current_assign = j;
                j = assign[current_assign];
            }
            cycle++;
        }
    }
    return cycles; //возвращаем наш вектор векторов(циклов)
};

string Prefix(const string& s1, int& n)
{
    return s1.substr(0, s1.size() - n);
};
