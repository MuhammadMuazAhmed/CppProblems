#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<string> name = {
        "muaz", "ahad", "hashir", "zaryab", "huzaifa"};
        string result = name[0];
    for (int i = 1; i < name.size(); i++)
    {
        int j = 0;
        while (j < result.size() && j < name.size() && result[j] == name[i][j])
        {
            j++;
        }
        result = result.substr(0, j);
        if (result.empty())
            
        cout << "Longest common prefix is \"" << result << "\".\n";
    }
}
