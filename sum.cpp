#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> res = {1, 2, 3, 4, 5};
    int target;
    cin >> target;
    for (int i = 0; i <= res.size(); i++)
    {
        for (int j = 0; j < res.size(); j++)
        {
            if (target == res[i] + res[j])
            {
                cout << i << "," << j << endl;
                return 0;
            }
        }
    }
    return 0;
}