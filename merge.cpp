#include <iostream>
using namespace std;
int main()
{
    int arr[4] = {1, 3, 5, 7};
    int brr[4] = {2, 4, 6, 8};
    int sum[8];
    for (int i = 0; i < 4; i++)
    {
        sum[i * 2] = arr[i];
        sum[i * 2 + 1] = brr[i];
    }
    for (int i = 0; i < 8; i++)
    {
        cout << sum[i] << " ";
    }
}