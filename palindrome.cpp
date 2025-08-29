#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string num=to_string(n);
    string nu=num;
    reverse(num.begin(),num.end());
    if(num==nu){
        cout<<"palendrome"<<endl;
    }
}
