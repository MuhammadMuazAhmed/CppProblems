#include <iostream>
using namespace std;
int main()
{
    int arr[10] = {0, 0, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 10; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (arr[i] == arr[j])
            {
                cout << "Duplicate element found" << endl;
                return 0;
            }
        }
    }
    cout << "No duplicate element found" << endl;
}