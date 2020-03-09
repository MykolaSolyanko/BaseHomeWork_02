#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    long n;
    bool found=false;
    long best;
    cout<<"Enter n\n";
    cin>>n;
    cout<<"Dividers are:\n";
    for(long i=n;i>0;--i){
        if(n%i==0){
            cout<<i<<endl;
            if(found==false&&i!=n){
                best=i;
                found=true;
            }

        }
    }
cout<<"And the best is "<<best<<endl;
    return 0;
}
