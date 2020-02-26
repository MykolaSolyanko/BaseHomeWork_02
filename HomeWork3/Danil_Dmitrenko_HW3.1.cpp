#include <iostream>
using namespace std;

void reverseString(string& str) 
{ 
    int n = str.length(); 
    for (int i = 0; i < n / 2; i++) 
        swap(str[i], str[n - i - 1]); 
}

int main(){
  cout<<"Enter \n";
  string abc;
  cin>>abc;
  reverseString(abc);
  cout<<abc; 
}