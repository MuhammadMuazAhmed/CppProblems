#include <iostream>
using namespace std;
int main()
{
  string my="hello";
  string s;
  int len = my.length();
  for(int i=len;i>=0;i--){
     s+= my[i]; 
  }
  cout<<s;
}