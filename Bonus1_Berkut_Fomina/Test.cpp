// Тестирующая программа
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdint>
#include <algorithm>
#include <set>
#include "Bonus.h"
using namespace std;

int main() {
    int number_strings;
    cin >> number_strings; // считаем кол-во строк
    set<string> input0;
    for (int i = 0; i < number_strings; i++)
    {
        string stroka;
        cin >> stroka;
        input0.insert(stroka);
    }   
    vector<string> input;
    input = DeleteSameStrings(input0);

    // Протестируем функцию Overlap и создание графа
    Graph graph(input);
    //graph.Print();

    // Протестируем функцию Assignment
    vector<int> assign;
    assign = Assignment(graph);
    //for (auto i : assign) cout << i << " ";

    // Протестируем функцию FullCoverage
    vector<vector<int>> full_coverage;
    full_coverage = FullCoverage(assign);
    /*
        for (auto i : full_coverage) {
        for (auto j : i) cout << j << " ";
        cout << endl;}
     */

    // Протестируем функцию
    /*vector<int> cycl;
    cycl = Minimize({1, 0, 2}, graph);
    for (auto i : cycl) cout << i << " ";*/

    // Протестируем функцию Cycle
    /*string s;
    s = Cycle({2, 1, 0}, graph, input);
    cout << s;*/

    // Протестируем Builder
    string res;
    res = Builder(full_coverage, graph, input);
    cout << res;

    return 0;
}
