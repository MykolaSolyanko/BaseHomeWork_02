#include <iostream>
using namespace std;

int main() {
  cout << "Enter a six digit number\n";
  unsigned int number;
  cin>>number;
  
  int sec = (number%10)+(number/10)%10+(number/100)%10;
  int fir = (number/1000)%10+(number/10000)%10+(number/100000)%10;
  if(fir==sec){
    cout << "Your ticket is lucky\n";
  }
  else{
    cout << "Your ticket isn't lucky\n"; 
  }
  return 0;
}
