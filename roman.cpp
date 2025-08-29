#include <iostream>
#include <unordered_map>
using namespace std;

int romanToInt(string s)
{
    // Map to store the values of Roman numerals
    unordered_map<char, int> roman = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 10},
        {'D', 500},
        {'M', 1000},
    };

    int result = 0;
    int pre = 0;
    for (int i = s.size() - 1; i >= 0; --i)
    {
        int value = roman[s[i]];
        if (value < pre)
        {
            result -= value;
        }
        else
            result += value;
        pre = value;
    }

    return result;
}

