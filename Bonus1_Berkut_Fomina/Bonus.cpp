#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <set>
#include "Bonus.h"

using namespace std;

// Функция, удаляющая одинаовые строки
vector<string> DeleteSameStrings(set<string>& input)
{
    vector<string> res;
    for (auto i: input)
        res.push_back(i);
    return res;
};

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

// Конструктор, создающий полный граф по набору строк input
Graph::Graph(const vector<string>& input)
{
    int n = input.size();
    size = n;
    matrix.resize(n); // Создаем пустую матрицу смежности размера n*n
    for (int i = 0; i < n; i++) // Заполняем матрицу смежности
    {
        for (int j = 0; j < n; j++)
            matrix[i].push_back(Overlap(input[i], input[j]));
    }    
};

// Получение размера графа
int Graph::GetSize() const
{
    return size;
};

// Получение графа
vector<vector<int>> Graph::GetMatrix() const
{
    return matrix;
};

// Получение значения ячейки [i][j]
int Graph::GetValue(int i, int j)
{
    return matrix[i][j];
};

// Печать графа
void Graph::Print()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
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
    for (int i = 0; i < n; i++)
        allow[i].assign(n, false); // Заполнили матрицу достуных клеток
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

// Функция для обрезания первой строки на ее overlap со второй
string Prefix(const string& s1, int n)
{
    return s1.substr(0, s1.size() - n);
};

/*
* Функция, сдвигающая цикл так,
* чтобы минимизировать overlap первой и последней строчек
*/
vector<int> Minimize(vector<int> v, Graph& g)
{
    vector<int> res;
    int n  = v.size();
    int min = g.GetValue(v[n-1], v[0]);
    int shift = 0;
    for (int i = 1; i < n; i++)
    {
        int x = g.GetValue(v[n - i - 1], v[n - i]);
        if (x < min)
        {
            min = x;
            shift = i;
        }
    }
    if (shift == 0) return v;
    else
    {
        res.resize(n);
        for (int i = shift; i < n; i++) res[i] = v[i - shift];
        for (int i = 0; i < shift; i++) res[i] = v[i + n - shift];
        return res;
    }
};

// Функция для сборки надстроки по одному циклу
string Cycle(vector<int> v, Graph g, vector<string> input)
{
    string res = "";
    for (int i = 0; i < v.size() - 1; i++)
    {
        res += Prefix(input[v[i]], g.GetValue(v[i], v[i+1]));
    }
    return res + input[v[v.size()-1]];
};


// Функция для сборки всех минимальных надстрок сдвинутых циклов
string Builder(const vector<vector<int>>& cycles, Graph& graph, const vector<string>& input)
{
    string result;
    for (int i = 0; i < cycles.size(); i++)
    {
        if (cycles[i].size() > 0) {
            vector<int> minimized_cycle;
            string nadstroka;
            minimized_cycle = Minimize(cycles[i], graph);
            nadstroka = Cycle(minimized_cycle, graph, input);
            result += nadstroka;
        }
    }
    return result;
};

