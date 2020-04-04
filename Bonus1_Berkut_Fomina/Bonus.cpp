#include <iostream>
#include <vector>
#include <string>

using namespace std;

int Overlap(const string& s1, const string& s2)
{
    int overlap = 0;
    int j = 0;
    int s1_size = s1.size() - 1;
    int s2_size = s2.size();
    for (int i = s1_size; i > -1; i--)
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


