#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    const int arr_count=50;
    int array[arr_count];
    int tmp,tmp2;
    int countofnumbers=0;
    int result1=0;
    
    cout<<"Enter int type numbers in range -60<=n<=90, if you want to stop, enter not number\n";
    for(int i=0;i<=arr_count;i++){
        //tmp2=tmp;
        //cin>>tmp;
        if(!(cin>>tmp))//if not changed
            break;
        if(tmp<-60||tmp>90){
            cout<<"Error, try again";
            return 0;
        }
            //cout<<tmp<<endl;

        if(!(tmp%2==0)){
            array[countofnumbers]=tmp;
            //cout<<array[i]<<endl;
            countofnumbers++;
        }
    }

    for(int i=0;i<=countofnumbers-1;i++){
        result1 += array[i];
        //cout<<result1<<endl;  
    }
    
    cout<<"Answer: "<<result1<<endl;
    return 0;
}
