// Тестирующая программа
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdint>
#include <algorithm>
#include <set>
#include "Bonus.h"
#include "Bonus.cpp"
using namespace std;

/*
* Здесь мы протестируем последовательно работу
* всех функций на примерах 3х наборов строк
*/

// Набор 1
set<string> set_1 = {"abc", "cde", "eab", "fgh", "ghf", "hed"};
vector<vector<int>> graph = {{0,1,0,0,0,0}, {0,0,1,0,0,0}, {2,0,0,0,0,0}, {0,0,0,0,2,1}, {0,0,0,1,0,0}, {0,0,0,0,0,0}};
vector<int> assign = {1, 2, 0, 4, 3, 5};
vector<vector<int>> full_coverage = {{0,1,2}, {3,4}, {5}};
string output = "eabcdefghfhed";
TEST (all_functions, set1) {
    Graph G = Graph(set_1);
    ASSERT_EQ(graph, G.GetMatrix);
    ASSERT_EQ(assign, Assignment(G));
    ASSERT_EQ(full_coverage, FullCoverage(assign));
    ASSERT_EQ(output, Builder(full_coverage, G, DeleteSameStrings(set_1)));
}

// Набор 2
set<string> set_2 = {"aa", "abba", "aca", "bac"};
graph = {{0,1,1,0}, {1,0,1,2}, {1,1,0,0}, {0,0,2,0}};
assign = {1, 3, 0, 2};
full_coverage = {{0,1,3,2}};
output = "aabbaca";
TEST (all_functions, set2) {
    Graph G = Graph(set_2);
    ASSERT_EQ(graph, G.GetMatrix);
    ASSERT_EQ(assign, Assignment(G));
    ASSERT_EQ(full_coverage, FullCoverage(assign));
    ASSERT_EQ(output, Builder(full_coverage, G, DeleteSameStrings(set_2)));
}
